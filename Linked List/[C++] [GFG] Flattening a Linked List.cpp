/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node* merge(Node *a, Node *b){
    
    Node *ans = new Node(0);
    Node *temp = ans;
    while(a != NULL && b!= NULL)
    {
        if(a->data < b->data)
        {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else{
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }
    if(a)
    {
        temp->bottom = a;
    }
    if(b)
    {
        temp->bottom = b;
    }
    return ans->bottom;
}

Node *flatten(Node *head)
{
   // Your code here
   
   //base case 
   if(head == NULL || head->next == NULL){
       return head;
   }
   
   head->next = flatten(head->next);
   
   head = merge(head, head->next);
   head->next = NULL;
   return head;
}