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
int ans = 0, maxDepth = -1;
    void solve(TreeNode* root, int depth){
        if(!root)
            return;
        
        depth++;
        
        solve(root->left, depth);

        if(depth > maxDepth){
            maxDepth = depth;
            ans = root->val;
        }

        solve(root->right, depth);
    }
    int findBottomLeftValue(TreeNode* root) {
        solve(root, 0);
        return ans;
    }
};