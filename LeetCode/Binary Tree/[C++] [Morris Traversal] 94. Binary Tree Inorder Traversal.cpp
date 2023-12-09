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

 /*
 Morris Traversal

 T.C -> O(n)
 S.C -> O(1) [No recursion or stack used]
 */
 
 /*
 Algo:-
 -> If left part doesn't exist, print the node and move right of it.
 -> Else
    -> Find the predecessor
        -> If the right of predecessor is NULL
            -> point it's right to the current node and make current move to it's left
        -> If not, that means right of predecessor is pointing to curr
            -> point right of predecessor to NULL
            -> print the current node
            -> make current move to it's right
 */

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)
            return ans;

        TreeNode *curr, *pre;
        curr = root;

        while(curr != NULL)
        {
            if(curr->left == NULL)
            {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                // Find inorder predecessor of current 
                pre = curr->left;
                while(pre->right != NULL && pre->right != curr)
                    pre = pre->right;
                
                if(pre->right == NULL)
                {
                    pre->right = curr;
                    curr = curr->left;
                }
                else
                {
                    pre->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }

            }
        }
        return ans;
    }
};


//Brute Force
/*
class Solution {
public:
    vector<int> ans;
    void solve(TreeNode* root){
        if(!root)
            return;
        
        if(root->left)
            solve(root->left);
        
        ans.push_back(root->val);

        if(root->right)
            solve(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        solve(root);
        return ans;
    }
};
*/