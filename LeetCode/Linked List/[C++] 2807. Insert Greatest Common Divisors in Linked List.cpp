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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;

        while(temp) {
            if(temp->next){
                ListNode* curr = temp;
                ListNode* nxt = temp->next;
                ListNode* GCD = new ListNode(min(curr->val, nxt->val));
                while(GCD->val){
                    if(curr->val % GCD->val == 0 && nxt->val % GCD->val == 0)
                        break;
                    
                    GCD->val--;
                }

                GCD->next = nxt;
                curr->next = GCD;

                temp = temp->next;
            }

            temp = temp->next;
        }

        return head;
    }
};