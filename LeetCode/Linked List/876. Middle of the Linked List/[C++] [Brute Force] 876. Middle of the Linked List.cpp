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
    int getLength(ListNode* head){
        int cnt=1;
        while(head->next != NULL){
            head = head->next;
            cnt++;
        }
        return cnt;
    }
public:
    ListNode* middleNode(ListNode* head) {
        int l = getLength(head);
        ListNode *temp = head;
        for(int i=1;i<(l/2)+1;i++)
        {
            temp = temp->next;
        }
        return temp;
    }
};