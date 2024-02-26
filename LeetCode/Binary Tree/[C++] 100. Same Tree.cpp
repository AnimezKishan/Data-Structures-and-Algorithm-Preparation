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
T.C -> O(n)
S.C -> O(min height possible in both tree)
*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;
        if((p != NULL && q == NULL) || (p == NULL && q!= NULL))
            return false;
        
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);

        bool identical = p->val == q->val;

        if(left && right && identical)
            return true;
        else
            return false;

    }
};


/*
class Solution {
public:
    bool identical = true;
    void solve(TreeNode* p, TreeNode* q){
        if(!p && !q){
            return;
        }

        if(!q || !p){
            identical = false;
            return;
        }

        if(p->val != q->val){
            identical = false;
            return;
        }

        solve(p->left, q->left);
        solve(p->right, q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        solve(p, q);
        return identical;    
    }
};
*/