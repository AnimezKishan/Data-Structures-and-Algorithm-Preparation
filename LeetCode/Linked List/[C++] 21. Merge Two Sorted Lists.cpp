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
    ListNode* solve(ListNode* list1, ListNode* list2){
        /*
        Here, 
        -> prev points to the previous node of list1
        -> curr points to current node of list1
        -> temp points to list2 (its is used to merge the node with list1 if required)
        -> temp2 also points to list2 (used to keep record of whole list2 node)
        */
        ListNode* prev = list1;
        ListNode* curr = list1->next;
        ListNode* temp = list2;
        ListNode* temp2 = temp->next;

        while(curr != NULL && temp != NULL)
        {
            if((prev->val <= temp->val) && (temp->val <= curr->val))
            {
                prev->next = temp;
                temp2 = temp->next;
                temp->next = curr;

                prev = temp;
                temp = temp2;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
            
        }
        if(curr == NULL)
        {
            prev->next = temp;
            return list1;
        }
        return list1;
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list2 == NULL) 
            return list1;
        if(list1 == NULL)
            return list2;
        
        if(list1->val <= list2->val)
            return solve(list1, list2);
        else
            return solve(list2, list1);
    }
};