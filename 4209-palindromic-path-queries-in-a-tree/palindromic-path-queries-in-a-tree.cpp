/**
 * Fenwick Tree (Binary Indexed Tree) for Range XOR Updates and Point Queries.
 * This implementation follows the standard BIT logic but uses XOR instead of addition.
 * * Citation/Reference for Fenwick Tree logic: 
 *https://cp-algorithms.com/data_structures/fenwick.html
 */
struct FenwickXor {
    int n;
    vector<int> bit; // 1-indexed array for the Fenwick Tree
    FenwickXor(int n=0){ init(n); }
    
    void init(int _n){ 
        n = _n; 
        bit.assign(n + 1, 0); 
    }

    // Standard BIT update: flips bits in the range responsible for index i
    void add(int i, int val){
        for(; i <= n; i += i & -i) bit[i] ^= val;
    }

    /**
     * Range XOR update [l, r]:
     * In a BIT, applying a value at 'l' and again at 'r+1' effectively 
     * applies that value to all point queries within [l, r] when using prefix XORs.
     */
    void range_xor(int l, int r, int val){
        if(l > r) return;
        add(l, val);
        if(r + 1 <= n) add(r + 1, val);
    }

    // Prefix XOR query: returns the XOR sum from index 1 to i
    int point(int i){
        int res = 0;
        for(; i > 0; i -= i & -i) res ^= bit[i];
        return res;
    }
};

class Solution {
public:
    int LOG = 20;               // Maximum power for Binary Lifting
    vector<vector<int>> up;     // Binary Lifting table (up[k][v] is 2^k-th ancestor)
    vector<int> depth, tin, tout; // Tree metadata for LCA and Euler Tour
    int timer = 0;
    vector<int> base_pref;      // XOR sum from root to node (initial state)
    vector<int> cur_mask;       // Current bitmask (1 << char) for each node
    FenwickXor bit;             // Manages dynamic updates to the tree paths
    vector<vector<int>> adj;

    /**
     * DFS Preparation:
     * 1. Assigns Entry (tin) and Exit (tout) times for subtree range queries.
     * 2. Computes initial prefix XORs from root to each node.
     * 3. Sets up the first level of the binary lifting table.
     */
    void dfs_prep(int v, int p){
        tin[v] = ++timer; // Map node to a linear timeline
        up[0][v] = p;
        depth[v] = (p == -1) ? 0 : depth[p] + 1;
        
        // Compute path XOR from root: Path(root, v) = Path(root, parent) ^ mask(v)
        base_pref[v] = (p == -1) ? cur_mask[v] : base_pref[p] ^ cur_mask[v];

        for(int to : adj[v]){
            if(to != p) dfs_prep(to, v);
        }
        tout[v] = timer; // End of this node's subtree in the linear timeline
    }

    /**
     * Lowest Common Ancestor (LCA) using Binary Lifting.
     * Complexity: O(log N)
     */
    int lca(int a, int b){
        if(depth[a] < depth[b]) swap(a, b);
        // Lift a up to the same depth as b
        int diff = depth[a] - depth[b];
        for(int k = 0; diff; ++k){
            if(diff & 1) a = up[k][a];
            diff >>= 1;
        }
        if(a == b) return a;
        // Lift both until they are just below the common ancestor
        for(int k = LOG - 1; k >= 0; --k){
            if(up[k][a] != -1 && up[k][a] != up[k][b]){
                a = up[k][a];
                b = up[k][b];
            }
        }
        return up[0][a];
    }

    // Helper to extract numbers from query strings (e.g., "q 1 2" -> {1, 2})
    pair<int,int> get_digits(const string &q){
        int a = 0, b = 0, i = 0;
        while(i < (int)q.size() && !isdigit(q[i])) ++i;
        while(i < (int)q.size() && isdigit(q[i])) { a = a * 10 + (q[i] - '0'); ++i; }
        while(i < (int)q.size() && !isdigit(q[i])) ++i;
        while(i < (int)q.size() && isdigit(q[i])) { b = b * 10 + (q[i] - '0'); ++i; }
        return {a, b};
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        adj.assign(n, {});
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        cur_mask.assign(n, 0);
        for(int i = 0; i < n; ++i) cur_mask[i] = 1 << (s[i] - 'a');

        tin.assign(n, 0); tout.assign(n, 0);
        base_pref.assign(n, 0); depth.assign(n, 0);

        LOG = log2(n) + 1;
        up.assign(LOG, vector<int>(n, -1));

        timer = 0;
        dfs_prep(0, -1);

        // Precompute the rest of the binary lifting table
        for(int k = 1; k < LOG; ++k){
            for(int v = 0; v < n; ++v){
                int mid = up[k-1][v];
                up[k][v] = (mid == -1 ? -1 : up[k-1][mid]);
            }
        }

        bit.init(n);
        vector<bool> ans;

        for(const string &Q : queries){
            if(Q.empty()) continue;
            
            if(Q[0] == 'q'){ 
                // QUERY CASE
                auto [u, v] = get_digits(Q);
                
                // Path XOR(u, v) = Pref(u) ^ Pref(v) ^ Node(LCA(u,v))
                // bit.point(tin[u]) retrieves the cumulative updates applied to node u
                int pref_u = base_pref[u] ^ bit.point(tin[u]);
                int pref_v = base_pref[v] ^ bit.point(tin[v]);
                int w = lca(u, v);
                
                // XORing LCA once because it is removed by pref_u ^ pref_v
                int path_xor = pref_u ^ pref_v ^ (cur_mask[w]);
                
                // Check if at most one bit is set (Power of 2 check)
                bool can_be_palindrome = (path_xor == 0) || ((path_xor & (path_xor - 1)) == 0);
                ans.push_back(can_be_palindrome);
            } else { 
                // UPDATE CASE
                auto [u, _ignore] = get_digits(Q);
                char newc = Q.back();
                int newmask = 1 << (newc - 'a');
                
                // Delta represents the bits that need to change
                int delta = cur_mask[u] ^ newmask;
                if(delta != 0){
                    /**
                     * Update Logic: Changing node u affects the prefix XOR of 
                     * every node in u's subtree. 
                     * In Euler tour (tin/tout), the subtree is the range [tin[u], tout[u]].
                     */
                    bit.range_xor(tin[u], tout[u], delta);
                    cur_mask[u] = newmask;
                }
            }
        }
        return ans;
    }
};