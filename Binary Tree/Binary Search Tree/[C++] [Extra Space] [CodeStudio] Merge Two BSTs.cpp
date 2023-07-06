#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

*************************************************************/

/*
T.C -> O(m+n) [m = size of root1, n = size of root2]
S.C -> O(m+n)
*/

void inorder(TreeNode<int> *root, vector<int> &bst)
{
    if(root == NULL)
        return;
    
    inorder(root->left, bst);
    bst.push_back(root->data);
    inorder(root->right, bst);
}

vector<int> merge(vector<int> &bst1,vector<int> &bst2)
{
    vector<int> ans(bst1.size()+bst2.size());

    int i = 0, j = 0, k = 0;

    while(i < bst1.size() && j < bst2.size())
    {
        if(bst1[i] < bst2[j])
            ans[k++] = bst1[i++];
        else
            ans[k++] = bst2[j++];
    }

    while(i < bst1.size())
        ans[k++] = bst1[i++];
    
    while(j < bst2.size())
        ans[k++] = bst2[j++];
    
    return ans;
}

TreeNode<int> *inorderToBST(int s, int e, vector<int> &ans)
{
    if(s > e)
        return NULL;

    int mid = s+(e-s)/2;
    TreeNode<int> *root = new TreeNode<int>(ans[mid]);
    root->left = inorderToBST(s, mid-1, ans);
    root->right = inorderToBST(mid+1, e, ans);
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // Step 1 - Find inorder of both bst
    vector<int> bst1, bst2;

    inorder(root1, bst1);
    inorder(root2, bst2);

    // Step 2 - Merge two sorted arrays logic
    vector<int> mergedBST = merge(bst1, bst2);

    //Step 3 - Form bst from merged array
    return inorderToBST(0, mergedBST.size()-1, mergedBST);
}