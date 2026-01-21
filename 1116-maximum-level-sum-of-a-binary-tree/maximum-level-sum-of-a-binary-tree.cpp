/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        // set<pair<int,int>> st;
        map<int,long long> sm;
        queue<pair<int,TreeNode*>> q;
        q.push({1,root});
        while(q.size()){
            auto node = q.front();
            q.pop();
            sm[node.first]+=node.second->val;
            if(node.second->left)q.push({node.first+1,node.second->left});
            if(node.second->right)q.push({
                node.first+1, node.second->right
            });
        }
        long long mx = -1e18;
        int ans = -1;
        for(auto &x: sm){
            if(x.second>mx)ans = x.first, mx = x.second; 
        }
        return ans;
    }
};