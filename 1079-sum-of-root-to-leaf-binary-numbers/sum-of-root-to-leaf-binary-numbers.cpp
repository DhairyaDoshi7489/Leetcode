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
    int sumRootToLeaf(TreeNode* root) {
        // vector<int> res;
        int val = dfs(root, 0);
        // for(auto &x: res)cout<<x<<" ";            
        return val;
    }
    int dfs(TreeNode* root, int val){
        if(root==NULL){
            // res.push_back(val);
            return val;
        }
        val<<=1;
        val|=root->val;
        if(root->left&&root->right)return dfs(root->left, val)+dfs(root->right, val);
        else if(root->right)return dfs(root->right, val);
        else return dfs(root->left, val);
    }
};