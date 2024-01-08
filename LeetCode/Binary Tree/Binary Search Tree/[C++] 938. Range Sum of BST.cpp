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
    vector<int> inOrder;
    void solve(TreeNode* root){
        if(!root)
            return;
        
        if(root->left)
            solve(root->left);
        
        inOrder.push_back(root->val);

        if(root->right)
            solve(root->right);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        solve(root);

        int j = 0, k = 0;
        for(int i=0;i<inOrder.size();i++){
            if(inOrder[i] == low)
                j = i;

            if(inOrder[i] == high)
                k = i;
        }

        return accumulate(begin(inOrder)+j, begin(inOrder)+k+1, 0);
    }
};