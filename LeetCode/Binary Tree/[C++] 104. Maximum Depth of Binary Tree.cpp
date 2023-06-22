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
 Using Recursion 
 -> Traverse the left and right child nodes and check which one has the maximum height.
    (1 is added to include the parent node or the current node on which the recursion is being applied.)

    T.C. -> O(n)
    S.C. -> O(height) [As, maximum space the recursive stack is taking is the height of tree.]
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        int ans = max(left, right) + 1;
        return ans;
    }
};