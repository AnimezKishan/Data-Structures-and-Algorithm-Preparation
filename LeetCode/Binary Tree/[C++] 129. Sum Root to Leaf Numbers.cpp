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
    int ans = 0;
    void solve(TreeNode* root, int prev){
        if(!root)
            return;
        if((!root->left && !root->right)){
            ans += prev*10 + root->val;
            return;
        }

        solve(root->left, prev*10 + root->val);
        solve(root->right, prev*10 + root->val);
    }
    int sumNumbers(TreeNode* root) {
        solve(root, 0);
        return ans;
    }
};