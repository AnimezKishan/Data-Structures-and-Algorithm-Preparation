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
    ListNode *list2End;
    int A, B;
    void solve(ListNode* temp, int count, ListNode* list2){

        if(count == B){
            list2End->next = temp->next;
            temp->next = NULL;
            return;
        }

        solve(temp->next, ++count, list2);

        if(count == A){
            temp->next = list2;
        }
    }
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *temp = list2;
        A = a;
        B = b;

        while(temp){
            if(!temp->next)
                list2End = temp;
            
            temp = temp->next;
        }
        
        temp = list1;

        solve(temp, 0, list2);
        return temp;
    }
};