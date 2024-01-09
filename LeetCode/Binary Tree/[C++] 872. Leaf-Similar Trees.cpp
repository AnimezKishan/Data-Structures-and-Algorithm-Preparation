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
    vector<int> leaf1, leaf2;
    void solve(TreeNode *root, vector<int> &leaf){
        if(!root->left && !root->right){
            leaf.push_back(root->val);
            return;
        }

        if(root->left)
            solve(root->left, leaf);

        if(root->right)
            solve(root->right, leaf);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        solve(root1, leaf1);
        solve(root2, leaf2);

        return leaf1 == leaf2;
    }
};