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

// Postorder Traversal: left -> right -> top

class Solution {
public:
    vector<int> postOrder;
    void solve(TreeNode* root){
        if(!root)
            return;
        
        solve(root->left);
        solve(root->right);

        postOrder.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        solve(root);
        return postOrder;
    }
};