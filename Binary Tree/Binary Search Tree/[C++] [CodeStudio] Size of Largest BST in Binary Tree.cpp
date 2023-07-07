#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

/*
maxi stores the maximum value exists in that particular BST.
mini stores the minimum value exists in that particular BST.
isBST tells if the tree is BST or not.
size is used to store the size of particular tree.
*/

class info{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solve(TreeNode<int> *root, int &ans)
{
    if(root == NULL)
        return {INT_MIN, INT_MAX, true, 0};
    
    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;
    //At leftmost of tree, size = That particular node (1) + left child (0) + right child (0);
    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    /*
    To be a BST,
    It's left and right child should also be a BST and leftMAX < root->data < rightMin
    */
    if(left.isBST && right.isBST && (left.maxi < root->data && root->data < right.mini))
        currNode.isBST = true;
    else
        currNode.isBST = false;
    
    if(currNode.isBST)
        ans = max(ans, currNode.size);
    
    return currNode;
}

int largestBST(TreeNode<int>* root) 
{
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}
