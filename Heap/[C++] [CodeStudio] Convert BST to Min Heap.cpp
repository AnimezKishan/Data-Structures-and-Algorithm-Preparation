#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

	class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};

*************************************************************/

/* 
-> Get the inorder traversal of tree and store it. 
-> Store the inorder values in that tree preorder wise (NLR).
*/

void inorder(BinaryTreeNode* root, vector<int> &ans)
{
	if(root == NULL)
		return;
	
	inorder(root->left, ans);

	ans.push_back(root->data);

	inorder(root->right, ans);

}

void solve(BinaryTreeNode* &root, vector<int> &ans, int &i)
{
	if(root == NULL)
		return;

	root->data = ans[i++];
	solve(root->left, ans, i);
	solve(root->right, ans, i);
}

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	// Store the inorder -> sorted values
	vector<int> sorted;

	inorder(root, sorted);

	//Push the inorder values in preorder wise.
	int index = 0;
	solve(root, sorted, index);
	return root;

}