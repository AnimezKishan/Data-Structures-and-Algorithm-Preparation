class Solution {
    public:
        int n;
    
        TreeNode* solve(const string& traversal, int& i, int depth) {
            if (i >= n)
                return NULL;
    
            int j = i;
            while (j < n && traversal[j] == '-') {
                j++;
            }
            
            int dash = j-i;
    
            if(depth != dash) {
                return NULL;
            }
    
            i += dash;
    
            int value = 0;
            while (i < n && isdigit(traversal[i])) {
                value = value * 10 + (traversal[i] - '0');
                i++;
            }
    
            TreeNode* root = new TreeNode(value);
    
            root->left  = solve(traversal, i, depth + 1);
            root->right = solve(traversal, i, depth + 1);
    
            return root;
        }
    
        TreeNode* recoverFromPreorder(string traversal) {
            n = traversal.length();
            int i = 0;
            return solve(traversal, i, 0);
        }
    
    };