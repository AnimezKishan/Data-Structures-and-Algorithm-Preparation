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

/* Two-Pointer Approach */
class Solution {
private:
    ListNode* getMiddle(ListNode* head){

        //No node present or when size of LL is 1
        if(head == NULL || head->next == NULL)
            return head;
            
        //when size of LL is 2
        if(head->next->next == NULL)
            return head->next;

        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast != NULL)
        {
            fast = fast->next;
            if(fast != NULL)
                fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
public:
    ListNode* middleNode(ListNode* head) {
        return getMiddle(head);
    }
};