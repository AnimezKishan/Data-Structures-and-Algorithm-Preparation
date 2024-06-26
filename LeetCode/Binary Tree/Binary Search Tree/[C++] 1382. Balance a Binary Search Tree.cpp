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
-> Convert the given BST into sorted array using Inorder Traversal.
-> Using that Sorted Array, make the Balanced BST.
*/

class Solution {
public:
    vector<int> vec;
    void inOrder(TreeNode* root) {
        if(!root)
            return;
        
        inOrder(root->left);
        vec.push_back(root->val);
        inOrder(root->right);
    }

    TreeNode* solve(int s, int e){
        if(s > e)
            return NULL;
        
        int mid = s + (e-s)/2;
        TreeNode* root = new TreeNode(vec[mid]);
        root->left = solve(s, mid-1);
        root->right = solve(mid+1, e);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        inOrder(root);
        int n = vec.size();

        return solve(0, n-1);
    }
};