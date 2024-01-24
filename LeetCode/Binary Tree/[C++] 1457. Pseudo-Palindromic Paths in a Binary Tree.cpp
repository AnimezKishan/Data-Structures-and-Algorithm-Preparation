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

 // Approach I - Using Frequency Array.
 /*
 Maintain a freq array to increment the freq of element. When you reach a node with no child , check the freq of elements in the array. if more than 1 
 element has odd freq then this can't be a pallindrome.
 */
class Solution {
public:
    int ans = 0;
    void solve(TreeNode* root, vector<int> arr){
        arr[root->val]++;

        if(!root->left && !root->right){
            int elem = 0;
            for(int i=1;i<=9;i++){
                if(arr[i]&1)
                    elem++;
                
                if(elem > 1)
                    return;
            }

            ans++;
            return;
        }

        if(root->left){
            solve(root->left, arr);
        }

        if(root->right)
            solve(root->right, arr);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> arr(10, 0);
        solve(root, arr);
        return ans;
    }
};

// Approach II - Using Set
// If we use a set to track the number of elements from the root to path, theoretically a palindrome path will contain only 0 or 1 element by the end.
 /* Palindrome would consist:
        -> one element with odd frequency, one with even freq. ( In set, One element would be left in this case)
        -> both with even freq. ( In set, No element would be left in this case)
 */
/*
class Solution {
public:
    int ans = 0;
    void solve(TreeNode* root, set<int> s){

        if(s.count(root->val))
            s.erase(root->val);
        else
            s.insert(root->val);
        
        if(!root->left && !root->right){
            if(s.size() <= 1)
                ans++;
            
            return;
        }

        if(root->left){
            solve(root->left, s);
        }

        if(root->right)
            solve(root->right, s);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        set<int> s;
        solve(root, s);
        return ans;
    }
};
*/