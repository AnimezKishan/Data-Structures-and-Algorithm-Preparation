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
    ListNode* temp;
    void solve(ListNode* head){
        if(!head->next)
            return;

        solve(head->next);

        if(temp->next && temp->next->next){
            ListNode* nxt = temp->next;
            temp->next = head->next;
            head->next->next = nxt;
            head->next = NULL;
            temp = nxt;
        }
    }
    void reorderList(ListNode* head) {
        temp = head;
        solve(head);
    }
};