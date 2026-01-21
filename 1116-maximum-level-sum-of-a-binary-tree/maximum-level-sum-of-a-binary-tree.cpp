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
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<int,int> mp;
        int sum = 0;
        int maxsum = 0;
        int level = 1;
        maxsum = root->val;
        sum = maxsum;
        mp[level] = maxsum;
        while(!q.empty()){
            // auto t = q.front();
            int size = q.size();
            sum = -1000000000;
            level++;
            for(int i = 0;i < size;i++){
                auto t = q.front();q.pop();
                if(t->left) {if(sum == -1000000000){sum = 0;}sum+=t->left->val;q.push(t->left);}
                if(t->right) {if(sum == -1000000000){sum = 0;}sum+=t->right->val;q.push(t->right);}
                // if(!t->right && !t->left && i==size-1) {mp[sum] = level;sum = 10000000;}

            }
            if(mp[sum]) {bool u = true;}
            else{
                maxsum=max(maxsum,sum);
                mp[sum] = level;
            }
        }
        return mp[maxsum];
    }
};