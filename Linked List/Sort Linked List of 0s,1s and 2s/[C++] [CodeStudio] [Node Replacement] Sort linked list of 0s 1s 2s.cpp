/********************************
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

********************************/

Node* sortList(Node *head)
{
    // Write your code here.
    
    //making one dummy in each so that it is easier to merge later.
    Node *zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    //create separate lists for 0s, 1s and 2s
    Node *temp = head;
    while(temp != NULL)
    {
        if(temp->data == 0)
        {
            zeroTail->next = temp;
            zeroTail = temp;
            
        }
        else if(temp->data == 1)
        {
            oneTail->next = temp;
            oneTail = temp;
        }
        else if(temp->data == 2)
        {
            twoTail->next = temp;
            twoTail = temp;
        }
        temp = temp->next;
    }

    //merge 3 sublist
    if(oneHead->next != NULL)
        zeroTail->next = oneHead->next;
    else
        zeroTail->next = twoHead->next;
    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    head = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}
