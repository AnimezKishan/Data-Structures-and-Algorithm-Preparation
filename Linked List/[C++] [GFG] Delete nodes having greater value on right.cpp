/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    private:
    Node* reverse(Node* head)
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *forward = NULL;
        while(curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr= forward;
        }
        return prev;
    }
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        head  = reverse(head);
        int maxi = head->data;
        Node* prev = head;
        Node* curr = head->next;
        Node* forward = NULL;
        while(curr != NULL){
            forward = curr->next;
            if(curr->data < maxi)
            {
                prev->next = curr->next;
                curr->next = NULL;
                curr = forward;
            }
            else{
                maxi = max(maxi, curr->data);
                prev = curr;
                curr = curr->next;
            }
        }
        
        head = reverse(head);
        return head;
    }
    
};