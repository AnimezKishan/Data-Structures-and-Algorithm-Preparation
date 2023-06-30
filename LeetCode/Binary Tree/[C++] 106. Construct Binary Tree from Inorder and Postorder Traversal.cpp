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
 Same as "Construct Binary Tree from Preorder and Inorder Traversal"
 Just for a change, for index, start traversing from end of postorder
 And firstly deal with right childrens then left  
 */

/*
T.C -> O(nlog(n))
S.C -> O(max height)
*/

class Solution {
public:
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int &index, int inOrderStart, int inOrderEnd, int n, map<int, int> &nodeToIndex)
    {
        if(index < 0 || inOrderStart > inOrderEnd)
            return NULL;

        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);
        int pos = nodeToIndex[element];

        // As in Postorder --> left-right-root. Therefore, dealing with right first. 
        root->right = solve(inorder, postorder, index, pos+1, inOrderEnd, n, nodeToIndex);
        root->left = solve(inorder, postorder, index, inOrderStart, pos-1, n, nodeToIndex);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int postOrderIndex = n-1;
        map<int, int> nodeToIndex;
        //Since, postorder.length == inorder.length
        for(int i=0;i<n;i++)
        {
            nodeToIndex[inorder[i]] = i;
        }

        TreeNode*  ans = solve(inorder, postorder, postOrderIndex, 0, n-1, n, nodeToIndex);
        return ans;
    }
};