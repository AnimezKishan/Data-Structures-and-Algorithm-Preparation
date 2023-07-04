/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        
        //In this, ancestor lies in right part of BST
        if(p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);

        //In this, ancestor lies in left part of BST
        if(p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        
        //In any other case, that node is the answer
        return root;

    }
};