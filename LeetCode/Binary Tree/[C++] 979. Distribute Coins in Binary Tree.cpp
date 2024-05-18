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

// No. of extra candies a node has = Candy it has + candy it received from left child + candy it received from left child - 1 (a candy it needs) 

class Solution {
public:
    int cost = 0;
    int solve(TreeNode *root){
        if(!root)
            return 0;

        int l = solve(root->left);
        int r = solve(root->right);

        /* Dry-Run Example 1 for clearity of why abs 
        ( when node returns -1, it means it's chilrens doesn't 
        offer extra coin and it also doesn't have any coin. So, 
        it will borrow from parent. )
        */
        cost += abs(l) + abs(r);

        return (l + r + root->val - 1);
    }
    int distributeCoins(TreeNode* root) {
        solve(root);

        return cost;
    }
};