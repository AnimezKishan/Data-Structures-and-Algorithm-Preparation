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

// Quick Sort (Data Replacement)
//CAUTION - Time limit exceedes for big test cases.

class Solution {
private:
    ListNode* getTail(ListNode* head){
        ListNode* temp = head;
        while(temp != NULL && temp ->next != NULL)
            temp = temp->next;
        return temp; 
    }

    ListNode* partition(ListNode* start, ListNode* end)
    {
        ListNode *pivot_prev = start;
        ListNode* curr = start;
        int pivot = end->val;
        while(start != end)
        {
            if(start->val <= pivot)
            {
                pivot_prev = curr;
                int temp = start->val;
                start->val = curr->val;
                curr->val = temp;
                curr = curr->next;
            }
            start = start->next;
        }
        int temp = end->val;
        end->val = curr->val;
        curr->val = temp;

        return pivot_prev;
    }

    void quickSortRec(ListNode* &start, ListNode* end)
    {
        if(start == end)
            return;
        ListNode* prev = partition(start, end);
        quickSortRec(start, prev);
        quickSortRec(prev->next, end);
    }

public:
    ListNode* sortList(ListNode* head) {
        ListNode* tail = getTail(head);
        quickSortRec(head, tail);
        return head;
    }
};