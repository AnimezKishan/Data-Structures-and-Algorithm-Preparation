/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

/*
    Step 1 -> Get middle of the LL.
    Step 2 -> Reverse the LL after middle.
    Step 3 -> Compare data between 'head' & 'middle->next'.
    Step 4 -> (Optional) Again reverse the reversed nodes so that we get the original LL back.
    
    T.C. ->O(n)
    S.C. ->O(1)
*/
class Solution{
  private:
    Node* getMiddle(Node* head){
        Node* fast = head->next;
        Node* slow = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    Node* reverse(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head->next == NULL)
            return true;
        
        //Step 1 -> find middle
        Node* middle = getMiddle(head);
        
        //Step 2 -> reverse the list after middle 
        Node* temp = middle->next;
        middle->next = reverse(temp);
        
        //Step 3 -> compare both
        Node* head1 = head;
        Node* head2 = middle->next;
        
        while(head2 != NULL)
        {
            if(head1->data != head2->data)
                return false;
            head1 = head1->next;
            head2 = head2->next;
        }
        
        temp = middle->next;
        middle->next = reverse(temp);
        return true;
    }
};