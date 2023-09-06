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
    int getLen(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while(temp)
        {
            count++;
            temp= temp->next;
        }
        return count;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = getLen(head);
        int size = len / k;
        int extra = len % k;
        vector<ListNode*> ans;

        ListNode* temp = head;
        int key=0;
        while(key<k)
        {
            int i=0;
            ListNode* head = NULL;
            ListNode* tail = NULL;

            while(i<size && temp)
            {
                if(head == NULL)
                {
                    head = temp;
                    tail = temp;
                }
                else{
                    tail->next = temp;
                    tail = tail->next;
                }
                temp = temp->next;
                i++;
            }

            if(extra>0 && temp)
            {
                if(tail == NULL)
                {
                    head = temp;
                    tail = temp;
                }
                else{
                    tail->next = temp;
                    tail = tail->next;
                }
                temp = temp->next;
                extra--;
            }

            if(tail)
                tail->next = NULL;
                
            ans.push_back(head);
            key++;
        }
        return ans;
    }
};