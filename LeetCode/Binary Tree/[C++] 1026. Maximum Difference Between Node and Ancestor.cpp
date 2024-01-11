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
class Solution {
public:
    int solve(TreeNode* root, int minVal, int maxVal){
        if(!root)
            return abs(minVal - maxVal);
        
        minVal = min(minVal, root->val);
        maxVal = max(maxVal, root->val);

        int l = solve(root->left, minVal, maxVal);
        int r = solve(root->right, minVal, maxVal);

        return max(l, r);
    }
    int maxAncestorDiff(TreeNode* root) {
        return solve(root, root->val, root->val);
    }
};