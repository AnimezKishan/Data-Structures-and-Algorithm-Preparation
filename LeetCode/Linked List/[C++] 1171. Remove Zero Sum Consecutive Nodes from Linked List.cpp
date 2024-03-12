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
Store Prefix-Sum in map
Example:-
1 -> 3 -> 2 -> -3 -> -2 -> 5 -> 5 -> -5 -> 1
1    4    6     3     1

Since a already seen value found, so change pointers
Also, remove values 4, 6, 3 from map.

1 -> 5 -> 5 -> -5 -> 1 
1    6    11    6

Therefore,
1 -> 5 -> 1
*/

class Solution {
public:
    unordered_map<int, ListNode*> occured;
    void solve(ListNode* head, int sum){
        if(!head)
            return;
        
        sum += head->val;
        
        if(occured[sum]){
            ListNode* temp = occured[sum];
            ListNode* start = temp->next;
            ListNode* end = head;
            int tempSum = sum;
            while(start != end){
                tempSum += start->val;
                occured.erase(tempSum);
                start = start->next;
            }

            temp->next = head->next;
        }
        else
            occured[sum] = head;
        
        solve(head->next, sum);

    }
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* temp = new ListNode(-1, head);
        solve(temp, 0);
        return temp->next;
    }
};