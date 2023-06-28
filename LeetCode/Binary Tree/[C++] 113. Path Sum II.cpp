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
 TC -> O(n^2) [In Worst Case, cost to copy path each time O(n) + cost to copy path to ans]
 SC ->O(height)
 */ 
class Solution {
public:
    void dfs(TreeNode *root, int targetSum, vector<int> &path, vector<vector<int>> &ans)
    {
        if(root == NULL)
            return;
        
        path.push_back(root->val);
        targetSum -= root->val;

        //leaf node
        if(root->left == NULL && root-> right == NULL)
        {
            if(targetSum == 0)
                ans.push_back(path);
        }

        else{
            dfs(root->left, targetSum, path, ans);
            dfs(root->right, targetSum, path, ans);
        } 

        //backtrack
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        vector<int> path;
        dfs(root, targetSum, path, ans);
        return ans;
    }
};