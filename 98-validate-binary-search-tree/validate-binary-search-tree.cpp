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
    bool isValidBST(TreeNode* root) {
        long long mn = -1e18, mx = 1e18;
        bool v = true;
        dfs(root, v, mx, mn);
        return v;
    }
    void dfs(TreeNode* root, bool &v, long long mx, long long mn){
        if(root==NULL)return;
        mx = max(mx, 1LL*root->val);
        mn = min(mn, 1LL*root->val);
        if(root->left&&root->left->val>=root->val){
            v = false;
            return;
        }
        if(root->right&&root->right->val<=root->val){
            v = false;
            return;
        }
        if(root->val<=mn||root->val>=mx){
            v = false;
            return;
        }
        if(root->left){
            dfs(root->left, v, root->val, mn);
        }
        if(root->right){
            dfs(root->right, v, mx, root->val);
        }
    }
};