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

/*
maxi stores the maximum value exists in that particular BST.
mini stores the minimum value exists in that particular BST.
isBST tells if the tree is BST or not.
size is used to store the size of particular tree.
*/
class info {
    public: 
    int maxi;
    int mini;
    bool isBST;
    int sum;
};

info solve(TreeNode* root, int &maxSum)
{
    if(root == NULL)
        return {INT_MIN, INT_MAX, true, 0};
    
    info left = solve(root->left, maxSum);
    info right = solve(root->right, maxSum);

    info currNode;
    //At leftmost of tree, sum = That particular node (root->val) + left child (0) + right child (0);
    currNode.sum = left.sum + right.sum + root->val;
    currNode.maxi = max(root->val, right.maxi);
    currNode.mini = min(root->val, left.mini);

    /*
    To be a BST,
    It's left and right child should also be a BST and leftMAX < root->data < rightMin
    */
    if(left.isBST && right.isBST && (left.maxi < root->val && right.mini > root->val))
        currNode.isBST = true;
    else
        currNode.isBST = false;
    
    if(currNode.isBST)
        maxSum = max(maxSum, currNode.sum);
    
    return currNode;
} 

class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int maxSum = 0; 
        info temp = solve(root, maxSum);
        return maxSum;
    }
};