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
 -> Take index element as root element.
 -> Find position of root element in inorder.
 -> recursive call for root->left till position of root element.
 -> recursive call for root->right from position of root element till inorder end.
 */

/*
T.C -> O(nlog(n))
S.C -> O(max height)
*/

class Solution {
public:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &index, int inOrderStart, int inOrderEnd, int n, map<int, int> &nodeToIndex)
    {
        if(index >= n || inOrderStart > inOrderEnd)
            return NULL;
        
        int element = preorder[index++];
        //Taking index element from preorder as root element
        TreeNode* root = new TreeNode(element);
        //extract position from map
        int pos = nodeToIndex[element];

        //recursive call
        root->left = solve(preorder, inorder, index, inOrderStart, pos-1, n, nodeToIndex);
        root->right = solve(preorder, inorder, index, pos+1, inOrderEnd, n, nodeToIndex);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0;
        map<int, int> nodeToIndex;
        int n = inorder.size();
        //create nodes_to_index mapping for inorder to extract position
        for(int i=0;i<n;i++)
        {
            nodeToIndex[inorder[i]] = i;
        }

        TreeNode* ans = solve(preorder, inorder, preOrderIndex, 0, n-1, n, nodeToIndex);
        return ans;
    }
};