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
        TreeNode *solve(int preStart, int postStart, int preEnd, vector<int> &preorder, vector<int> &postorder) {
            if(preStart > preEnd)
                return NULL;
            
            TreeNode * root = new TreeNode(preorder[preStart]);
            if(preStart == preEnd)
                return root;
            int nextNode = preorder[preStart + 1];
    
            int j = postStart;
            while(postorder[j] != nextNode) {
                j++;
            }
    
            int num = j - postStart + 1;
    
            root->left = solve(preStart+1, postStart, preStart+num, preorder, postorder);
            root->right = solve(preStart+num+1, j+1, preEnd, preorder, postorder);
    
            return root;
        }
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
            int n = preorder.size();
            return solve(0, 0, n-1, preorder, postorder);
        }
    };