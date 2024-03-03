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

// Fast and Slow Pointer
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head;
        ListNode *slow = head;

        for(int i=0;i<n;i++){
            fast = fast->next;
        }

        if(!fast)
            return head->next;
        
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        auto temp = slow->next;
        slow->next = temp->next;
        temp->next = NULL;
        delete temp;

        return head;
    }
};


// DFS
/*
class Solution {
public:
    void solve(ListNode* head, int &n){
        if(!head){
            return;
        }
        solve(head->next, n);
        if(n == 0){
            auto temp = head->next;
            head->next = temp->next;
            temp->next = NULL;
            delete temp;
            n--;
        }
        else{
            n--;
        }
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = new ListNode(-1, head);
        solve(temp, n);
        if(!temp->next)
            return NULL;
        return temp->next;
    }
};
*/