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
private:ListNode* getMiddle(ListNode* head){
    ListNode* fast = head->next;
    ListNode* slow = head;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

ListNode* merge(ListNode* left, ListNode* right){
    if(left == NULL)
        return right;
    if(right == NULL)
        return left;
    
    ListNode* m = new ListNode(-1);
    ListNode* temp = m; 
    while(left != NULL && right != NULL)
    {
        if(left->val <= right->val)
        {
            temp->next = left;
            temp = temp->next;
            left = left->next;
        }
        else{
            temp->next = right;
            temp = temp->next;
            right = right->next;
        }
    }

    while(left != NULL)
    {
        temp->next = left;
        temp = temp->next;
        left = left->next;
    }
    while(right != NULL)
    {
        temp->next = right;
        temp = temp->next;
        right = right->next;
    }

    m = m->next;
    return m;
}

public:
    ListNode* sortList(ListNode* head) {
    //base case
    if(head == NULL || head->next == NULL)
        return head;

    //break LL into two halves
    ListNode* middle = getMiddle(head);
    ListNode* left = head;
    ListNode* right = middle->next;
    middle->next = NULL;

    //recursive calls
    left = sortList(left);
    right = sortList(right);

    //merge both left and right halves.
    ListNode* ans = merge(left, right);

    return ans;
    }
};