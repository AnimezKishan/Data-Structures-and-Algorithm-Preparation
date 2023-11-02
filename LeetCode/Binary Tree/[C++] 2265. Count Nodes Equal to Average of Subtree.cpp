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

//DFS
class Solution {
public:
    int ans;
    pair<int, int> solve(TreeNode* root){
        if(!root)
            return {0, 0};
        
        auto l = solve(root->left);
        auto r = solve(root->right);

        int currSum = l.first + r.first + root->val;
        int currCount = l.second + r.second + 1; 
        int avg = currSum/currCount;
        if(avg == root->val)
            ans += 1;
        
        return {currSum, currCount};
    }
    int averageOfSubtree(TreeNode* root) {
        ans = 0;
        solve(root);
        return ans;
    }
};


//Brute Force
/*
class Solution {
public:
    int ans = 0;
    int findSum(TreeNode* root, int &count){
        if(!root)
            return 0;

        count++;
        int lSum = findSum(root->left, count);
        int rSum = findSum(root->right, count);

        return lSum + rSum + root->val;
    }
    void solve(TreeNode* root)
    {
        if(!root)
            return;
        
        int count = 0;
        int sum = findSum(root, count);
        if(root->val == floor(sum/count))
            ans++;
        
        solve(root->left);
        solve(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};
*/