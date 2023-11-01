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
    vector<int> inorder;

    //Inorder traversal return nodes in sorted order.
    void solve(TreeNode* root){
        if(!root)
            return;
        
        solve(root->left);
        inorder.push_back(root->val);
        solve(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        solve(root);
        int currNo = 0, currFreq = 0, maxFreq = 0;
        vector<int> ans;

        for(int i:inorder){
            if(i == currNo)
                currFreq++;
            else{
                currNo = i;
                currFreq = 1;
            }

            if(currFreq == maxFreq)
                ans.push_back(currNo);
            
            if(currFreq > maxFreq){
                ans.resize(0);
                maxFreq = currFreq;
                ans.push_back(currNo);
            }
        }

        return ans;
        
    }
};

/*
Initial Intuition
class Solution {
public:
    map<int, int> m;
    void solve(TreeNode* root){
        if(!root)
            return;
        
        m[root->val]++;
        solve(root->left);
        solve(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        solve(root);
        int maxi = INT_MIN;
        vector<int> ans;
        for(auto i:m){
            if(i.second == maxi)
                ans.push_back(i.first);
            
            if(i.second > maxi)
            {
                ans.resize(0);
                maxi = i.second;
                ans.push_back(i.first);
            }
        }

        return ans;
    }
};
*/