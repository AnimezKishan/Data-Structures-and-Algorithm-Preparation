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
class FindElements {
    public:
        unordered_map<int, bool> mp;
        void solve(TreeNode* root) {
            if(!root)
                return;
            
            if(root->left) {
                root->left->val = 2*root->val + 1;
                mp[root->left->val] = true;
            }
            if(root->right) {
                root->right->val = 2*root->val + 2;
                mp[root->right->val] = true;
            }
    
            solve(root->left);
            solve(root->right);
        }
        FindElements(TreeNode* root) {
            root->val = 0;
            mp[0] = true;
    
            solve(root);
        }
        
        bool find(int target) {
            if(mp.find(target) == mp.end())
                return false;
            return true;
        }
    };
    
    /**
     * Your FindElements object will be instantiated and called as such:
     * FindElements* obj = new FindElements(root);
     * bool param_1 = obj->find(target);
     */