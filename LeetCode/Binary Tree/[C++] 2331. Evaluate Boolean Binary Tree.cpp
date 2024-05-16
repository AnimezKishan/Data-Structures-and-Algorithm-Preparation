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
    void solve(TreeNode* root){
        if(!root->left && !root->right)
            return;
        
        solve(root->left);
        solve(root->right);

        if(root->val == 2)
            root->val = root->left->val | root->right->val;
        else if(root->val == 3)
            root->val = root->left->val & root->right->val;
    }
    bool evaluateTree(TreeNode* root) {
        solve(root);
        return root->val;
    }
};