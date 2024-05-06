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

// Monotonic Stack + Recursion

class Solution {
public:
    ListNode* temp1;
    ListNode* temp1Head;
    void solve(stack<int> &st){
        if(st.empty()){
            temp1 = new ListNode(-1);
            temp1Head = temp1;
            return;
        }

        int value = st.top();
        st.pop();
        solve(st);

        ListNode *temp = new ListNode(value);
        temp1->next = temp;
        temp1 = temp1->next;
    }
    ListNode* removeNodes(ListNode* head) {
        stack<int> st;
        while(head){
            int top = head->val;
            while(!st.empty() && top > st.top()){
                st.pop();
            }

            st.push(top);
            head = head->next;
        }

        solve(st);
        return temp1Head->next;
    }
};