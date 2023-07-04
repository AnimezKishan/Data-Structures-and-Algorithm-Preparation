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

 //Approach 1- Get the Inorder Traversal and check if it is sorted or not.

 //Approach 2- Set a min and max value for every node for comparison

 /*
 T.C -> O(n)
 S.C -> O(Height)
 */
 
class Solution {
public:
    bool isBST(TreeNode* root, long long int min, long long int max)
    {
        if(root == NULL)
            return true;
        
        if(root->val > min && root->val < max)
        {
            //left childs should be smaller than the root node.
            bool left = isBST(root->left, min, root->val);

            //right childs should be greater than root node.
            bool right = isBST(root->right, root->val, max);

            return left && right;
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return isBST(root, -100000000000, 100000000000);
    }
};