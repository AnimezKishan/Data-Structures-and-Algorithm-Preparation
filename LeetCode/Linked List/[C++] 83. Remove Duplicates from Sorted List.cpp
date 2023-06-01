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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* curr = head;
        while(curr != NULL)
        {
            if( (curr->next != NULL) && curr->val == curr->next->val )
            {
                ListNode* nodetoPoint = curr->next->next;
                delete(curr->next);
                curr->next = nodetoPoint;
            }
            else{
                curr = curr->next;
            }
        }
        return head;
    }
};