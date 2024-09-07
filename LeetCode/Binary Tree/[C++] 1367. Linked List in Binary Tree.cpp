/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isPath = false;
    void findPath(TreeNode* root, ListNode* head) {
        if(!head){
            isPath = true;
            return;
        }

        if(!root)
            return;
        
        if(root->left && root->left->val == head->val)
            findPath(root->left, head->next);
        
        if(root->right && root->right->val == head->val)
            findPath(root->right, head->next);
        
    }
    void solve(TreeNode* root, ListNode *head) {
        if(isPath)
            return;
        
        if(!root)
            return;
        
        if(root->val == head->val)
            findPath(root, head->next);
        
        solve(root->left, head);
        solve(root->right, head);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        solve(root, head);
        return isPath;
    }
};