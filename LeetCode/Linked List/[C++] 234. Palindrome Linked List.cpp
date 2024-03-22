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
class Solution {
public:
    int size = 0, tempSize = 0;
    ListNode* temp;
    bool ans = true;
    void solve(ListNode* head){
        if(!head){
            tempSize = size;
            return;
        }

        ++size;

        solve(head->next);

        if(size >= tempSize/2){
            if(head->val != temp->val)
                ans = false;
            
            temp = temp->next;
        }
    }
    
    bool isPalindrome(ListNode* head) {
        temp = head;
        solve(head);
        return ans;
    }
};