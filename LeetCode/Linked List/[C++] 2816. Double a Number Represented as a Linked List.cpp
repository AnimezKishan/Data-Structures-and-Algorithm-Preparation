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
    void solve(ListNode* temp, int &carry){
        if(!temp)
            return;
        
        int value = temp->val;
        solve(temp->next, carry);

        value *= 2;
        temp->val = value%10 + carry;
        carry = (value >= 10) ? 1 : 0;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* temp = head;

        int carry = 0;
        solve(temp, carry);

        if(carry == 1){
            ListNode* carryLeft = new ListNode(1);
            carryLeft->next = head;
            head = carryLeft;
        }
        return head;

    }
};