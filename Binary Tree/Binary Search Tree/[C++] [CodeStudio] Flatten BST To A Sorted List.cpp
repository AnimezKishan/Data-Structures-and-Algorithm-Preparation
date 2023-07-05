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
void inorder(TreeNode<int>* root, vector<int> &inorderVal)
{
    if(root == NULL)
        return;
    
    inorder(root->left, inorderVal);
    inorderVal.push_back(root->data);
    inorder(root->right, inorderVal);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    // store inorder -> sorted values
    vector<int> inorderVal;
    inorder(root, inorderVal);

    //create a node and store all the values in it's right branch
    TreeNode<int>* newRoot = new TreeNode<int>(inorderVal[0]);

    TreeNode<int>* curr = newRoot;

    for(int i=1;i<inorderVal.size();i++)
    {
        TreeNode<int>* temp = new TreeNode<int>(inorderVal[i]);
        curr->left = NULL;
        curr->right = temp; 
        curr = temp;
    }

    //both left and right would be null for the last node.
    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
}
