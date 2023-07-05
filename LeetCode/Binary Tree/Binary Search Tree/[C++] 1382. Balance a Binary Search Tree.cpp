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
 -> Store the inorder traversal in a vector.
 -> Take the mid value of vector as root node and store left values in left child and store right values in right child.
 -> Repeat the second step using recursion until its done.
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int> &inorderVal)
    {
        if(root == NULL)
            return;
        
        inorder(root->left, inorderVal);
        inorderVal.push_back(root->val);
        inorder(root->right, inorderVal);
    }

    TreeNode* balancedBST(int s, int e, vector<int> &inorderVal)
    {
        if(s>e)
            return NULL;
        
        int mid = s+(e-s)/2;
        TreeNode* root = new TreeNode(inorderVal[mid]);
        root->left = balancedBST(s, mid-1, inorderVal);
        root->right = balancedBST(mid+1, e, inorderVal);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
    // store inorder -> sorted values
    vector<int> inorderVal;
    inorder(root, inorderVal);

    return balancedBST(0, inorderVal.size()-1, inorderVal);
    }
};