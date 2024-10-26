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
    // what if there is only unidirectional tree of size n
    int level[100001];
    int height[100001];
    int lvlMaxHeight[100001];
    int lvlSecondMaxHeight[100001];
    int findHeight(TreeNode* root, int lvl) {
        if(!root)
            return 0;
        
        level[root->val] = lvl;

        height[root->val] = max(findHeight(root->left, lvl+1), findHeight(root->right, lvl+1)) + 1;

        if(lvlMaxHeight[lvl] < height[root->val]){
            lvlSecondMaxHeight[lvl] = lvlMaxHeight[lvl];
            lvlMaxHeight[lvl] = height[root->val];
        }
        else if(lvlSecondMaxHeight[lvl] < height[root->val])
            lvlSecondMaxHeight[lvl] = height[root->val];

        return height[root->val];

    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        findHeight(root, 0);

        vector<int> ans;

        for(int &query : queries) {
            // if node which makes max height is being deleted, take second max height of same level. Otherwise, take node which has max height of that level.

            int l = level[query];
            int h = (lvlMaxHeight[l] == height[query] ? lvlSecondMaxHeight[l] : lvlMaxHeight[l]) - 1;

            ans.push_back(l+h);
        }

        return ans;
    }
};