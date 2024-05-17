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
    void solve(TreeNode* root, int &target){
        if(!root){
            return;
        }

        if(!root->left && !root->right && root->val == target){
            root->val = -1;
            return;
        }

        solve(root->left, target);
        solve(root->right, target);

        if(root->left && root->left->val == -1){
            TreeNode *temp = root->left;
            root->left = NULL;
            delete temp;
        } 

        if(root->right && root->right->val == -1){
            TreeNode *temp = root->right;
            root->right = NULL;
            delete temp;
        } 

        if(!root->left && !root->right && root->val == target){
            root->val = -1;
        }
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        solve(root, target);
        return root->val == -1 ? NULL : root;
    }
};