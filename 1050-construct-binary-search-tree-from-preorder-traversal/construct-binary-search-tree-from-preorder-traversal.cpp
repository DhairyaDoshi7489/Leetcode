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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int st = 0;
        return bst(preorder, st, INT_MAX);
    }
    TreeNode* bst(vector<int> &preorder, int& st, int mx){
        if(st>=preorder.size()||preorder[st]>mx)return NULL;
        TreeNode* root = new TreeNode(preorder[st]);
        st++;
        root->left = bst(preorder, st, root->val);
        root->right = bst(preorder, st, mx);

        return root;
    }
};