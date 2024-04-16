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
    void solve(TreeNode* root, int val, int depth, int k){
        if(!root)
            return;
        
        if(k+1 == depth){
            if(root->left){
                TreeNode *next = root->left;
                TreeNode *temp = new TreeNode(val);
                root->left = temp;
                temp->left = next;
            }
            else{
                TreeNode *temp = new TreeNode(val);
                root->left = temp;
            }

            if(root->right){
                TreeNode *next = root->right;
                TreeNode *temp = new TreeNode(val);
                root->right = temp;
                temp->right = next;
            }
            else{
                TreeNode *temp = new TreeNode(val);
                root->right = temp;
            }

            return;
        }

        solve(root->left, val, depth, k+1);
        solve(root->right, val, depth, k+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }
        solve(root, val, depth, 1);
        return root;
    }
};