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
T.C -> O(n)
S.C -> O(height)
*/

class Solution {
private:
    void solve(TreeNode *root, vector<int> &ans, int lvl)
    {
        if(root == NULL)
            return;
            
        if(lvl == ans.size())
            ans.push_back(root->val);
        
        solve(root->right, ans, lvl+1);
        solve(root->left, ans, lvl+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)
            return ans;
        
        solve(root, ans, 0);
        return ans;
    }
};