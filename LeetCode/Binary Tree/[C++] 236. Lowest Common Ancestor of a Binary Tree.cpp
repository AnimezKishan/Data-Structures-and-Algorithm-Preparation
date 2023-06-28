/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /*
 -> Store the root if it is equal to p or q node.
 -> The recursive calls meet at the lowest common ancestor if both p and q are found.

 T.C -> O(n)
 S.C -> O(max heigth)
 */
class Solution {
private:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return NULL;
        
        if(root == p || root == q)
        {
            return root;
        }

        TreeNode* leftAns = solve(root->left, p, q);
        TreeNode* rightAns = solve(root->right, p, q);

        if(leftAns != NULL && rightAns != NULL)
            return root;
        
        else if(leftAns != NULL && rightAns == NULL)
            return leftAns;
        
        else if(rightAns != NULL && leftAns == NULL)
            return rightAns;

        else
            return NULL;

    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
    }
};