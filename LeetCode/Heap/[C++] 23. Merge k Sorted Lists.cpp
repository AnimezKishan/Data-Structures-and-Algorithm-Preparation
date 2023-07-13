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
-> Insert first node of all k lists inside a min heap.
-> Insert all elements in a LL using min heap.
*/

/*
T.C -> O(k log(k)) + O((n*k-k)log(k)) -> O(k log(k)) + O((n*k)log(k)) -> O((n*k)log(k)) [N = Total No. of nodes in a list, k = No. of lists]
S.C -> O(k)
*/

class compare {
    public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> min_heap;

        int k = lists.size();
        
        if(k == 0)
            return NULL;

        //Step 1
        for(int i = 0;i<k;i++)
        {
            if(lists[i] != NULL)
                min_heap.push(lists[i]);
        }

        //Step 2
        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(min_heap.size() > 0)
        {
            ListNode* temp = min_heap.top();
            min_heap.pop();

            //if next node exist inside that particular list, put its next element inside linked list.
            if(temp->next != NULL)
                min_heap.push(temp->next);

            //answer LL is empty.
            if(head == NULL)
            {
                head = temp;
                tail = temp;
            }

            //insert at linked list.
            else
            {
                tail->next = temp;
                tail = temp;
            }
        }

        return head;
    }
};