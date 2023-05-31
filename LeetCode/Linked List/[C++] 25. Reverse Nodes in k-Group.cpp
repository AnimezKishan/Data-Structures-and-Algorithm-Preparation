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
private:
    ListNode* reverse(ListNode* head, int size, int k){
        //only returns function when no element left in linked list OR no. of elements left are no more multiple of 'k'
        if(head == NULL || size<k)
            return head;

        //reverse elements till k times
        ListNode *forward = NULL;
        ListNode *prev = NULL;
        ListNode *curr = head;
        int cnt = 0;
        while(curr != NULL && cnt<k)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            cnt++;
        }

        //point the head->next to either returned head or prev based on what satisfies the recursive call
        head->next = reverse(forward, size-k, k);

        //As we know, after reversal, the last element should be the one head should be pointing to 
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = 0;
        ListNode *temp = head;
        while(temp != NULL)
        {
            temp = temp->next;
            size++;
        }
        return reverse(head, size, k);
    }
};