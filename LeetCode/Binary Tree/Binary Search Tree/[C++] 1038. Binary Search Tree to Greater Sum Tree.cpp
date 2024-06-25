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
    void solve(TreeNode* root, int &prevSum){
        if(!root->left && !root->right && prevSum == 0){
            prevSum = root->val;
            return;
        }

        if(root->right)
            solve(root->right, prevSum);
        
        root->val = prevSum + root->val;
        prevSum = root->val;

        if(root->left)
            solve(root->left, prevSum);

    }
    TreeNode* bstToGst(TreeNode* root) {
        int prevSum = 0;
        solve(root, prevSum);

        return root;
    }
};