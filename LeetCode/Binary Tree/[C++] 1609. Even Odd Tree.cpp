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
    unordered_map<int, int> depthLastVal;
    bool ans = true;

    void solve(TreeNode* root, int level){
        if(!root)
            return;

        if(depthLastVal.find(level) == depthLastVal.end()){
            depthLastVal[level] = root->val;
            // even-indexed level
            if(level%2 == 0 && root->val%2 == 0){
                ans = false;
                return;
            }
            // odd-indexed level
            else if(level%2 != 0 && root->val%2 != 0){
                ans = false;
                return;
            }
        }
        else{
            // even-indexed level
            if(level%2 == 0 && root->val%2 != 0 && root->val > depthLastVal[level]){
                depthLastVal[level] = root->val;
            }
            // odd-indexed level
            else if(level%2 != 0 && root->val%2 == 0 && root->val < depthLastVal[level]){
                depthLastVal[level] = root->val;
            }
            else{
                ans = false;
                return;
            }
        }

        level++;
        solve(root->left, level);
        solve(root->right, level);
    }
    bool isEvenOddTree(TreeNode* root) {
        solve(root, 0);
        return ans;
    }
};