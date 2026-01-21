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
        vector<int> sm;
        queue<pair<int,TreeNode*>> q;
        q.push({1,root});
        while(q.size()){
            auto node = q.front();
            q.pop();
            if(node.first-1==sm.size())sm.push_back(0);
            sm[node.first-1]+=node.second->val;
            if(node.second->left)q.push({
                node.first+1,node.second->left});
            if(node.second->right)q.push({
                node.first+1, node.second->right
            });
        }
        long long mx = -1e18;
        int ans = -1;
        for(int i=0;i<sm.size();i++){
            if(sm[i]>mx)ans = i+1,mx = sm[i];
        }
        return ans;
    }
};