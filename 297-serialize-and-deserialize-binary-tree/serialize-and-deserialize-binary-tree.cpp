/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    int getNum(string& s, int& idx){
        int sign = 1, num = 0, prev = idx;
        if(s[idx] == '-'){
            sign = -1;
            idx++;
        }
        while(s[idx] != ','){
            num = num * 10 + s[idx++] - '0';
        }
        idx++;
        if(idx - prev == 1) return -1002;
        else return sign * num;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        queue<TreeNode*>q;
        string data = "";
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                auto curr = q.front();
                q.pop();
                if(!curr){
                    data.push_back(',');
                    continue;
                }
                data += to_string(curr->val);
                data.push_back(',');
                if(curr->left){
                    q.push(curr->left);
                }else{
                    q.push(NULL);
                }
                if(curr->right){
                    q.push(curr->right);
                }else{
                   q.push(NULL);
                }
            }
        }
        //cout << data;
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0) return NULL;
        int idx = 0, rootNum = getNum(data, idx), n = data.length();
        // cout << root;
        if(rootNum == -1002) return NULL;
        TreeNode* root = new TreeNode(rootNum);
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty() && idx < n){
            int n = q.size();
            for(int i = 0; i < n; i++){
                auto curr = q.front();
                q.pop();
                int left = getNum(data, idx);
                int right = getNum(data, idx);
                if(left != -1002){
                    auto node = new TreeNode(left);
                    curr->left = node;
                    q.push(node);
                }
                if(right != -1002){
                    auto node = new TreeNode(right);
                    curr->right = node;
                    q.push(node);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));