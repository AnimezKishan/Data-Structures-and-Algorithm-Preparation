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
        unordered_map<int, int> depth;
        int maxD = 0;
        void findDepth(TreeNode *root, int d) {
            if(!root)
                return;
            
            maxD = max(maxD, d);
            depth[root->val] = d;
            findDepth(root->left, d+1);
            findDepth(root->right, d+1);
        }
    
        TreeNode* LCA(TreeNode* root) {
            if(root == NULL || depth[root->val] == maxD) 
                return root;
            
            TreeNode* l = LCA(root->left);
            TreeNode* r = LCA(root->right);
    
            if(l && r) 
                return root;
            
            return l != NULL ? l : r;
        }
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            findDepth(root, 0);   
    
            return LCA(root); 
        }
    };