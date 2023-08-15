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

/*
Two Pointer

-> Make two LL to keep record
-> Store values less than 'x' in left LL
-> Store values greater than/equal to 'x' in right LL
-> Link the ending node of left with right
-> Since rightTail's node's next was pointing to a different node because of original LL. So make it point to NULL. 
*/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = new ListNode(0);
        ListNode* right = new ListNode(0);

        ListNode* leftTail = left;
        ListNode* rightTail = right;

        while(head != NULL)
        {
            if(head->val < x)
            {
                leftTail->next = head;
                leftTail = leftTail->next;
            }
            else{
                rightTail->next = head;
                rightTail = rightTail->next;
            }
            head = head->next;
        }

        leftTail->next = right->next;
        rightTail->next = NULL;

        return left->next;
    }
};