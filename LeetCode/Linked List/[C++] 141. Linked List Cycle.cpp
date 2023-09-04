/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
T.C -> O(n)
S.C -> O(1)
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fastPtr = head;
        ListNode *slowPtr = head;
        while(slowPtr && fastPtr->next && fastPtr->next->next)
        {
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
            if(fastPtr == slowPtr)
                return true;
        }

        return false;
    }
};