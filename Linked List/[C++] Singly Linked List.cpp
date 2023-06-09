#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    //destructor
    ~Node(){
        int value = this->data;
        if(this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is freed for node with value: "<<value<<endl;
    }
    
};

int getLength(Node* &head){
    int cnt =0;
    Node *temp = head;
    while(temp != NULL)
    {
        cnt++;
        temp =temp->next;
    }
    return cnt;
}

void insertAtHead(Node* &head, int d){
    //if passed head is already empty.
    if(head == NULL){
        Node *temp = new Node(d);
        head = temp;
        return;
    }

    Node *temp=new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d)
{
    //if passed tail is already empty.
    if(tail == NULL){
        Node *temp = new Node(d);
        tail = temp;
        return;
    }

    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d)
{
    //if insertion in starting position
    if(position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    if(position>getLength(head))
    {
        cout<<"Enter a position within the length of Linked List!!"<<endl;
        return;
    }
    
    int cnt = 1;
    Node *temp = head;
    while(cnt<position-1){
        temp = temp->next;
        cnt++;
    }
    
    //if insertion in ending position
    if(temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
    
    Node *NodeToInsert = new Node(d);
    NodeToInsert->next = temp->next;
    temp->next = NodeToInsert;
}

void deleteNode(Node* &head, Node* &tail, int position){
    //if deleting the starting position
    if(position == 1)
    {
        Node *temp = head;
        head = temp->next;
        temp->next = NULL;
        //calls destructor
        delete temp;
    }
    else{
        Node *curr = head;
        Node *prev = NULL;
        
        int cnt = 1;
        while(cnt < position){
            if(cnt == position-1)
                prev = curr;
            curr = curr->next;
            cnt++;
        }
        
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        
        //if deleting the ending position, place tail to its right position.
        if(prev->next == NULL)
        {
            tail = prev;
        }
    }
}

void print(Node* &head){
    Node *temp = head;
    
    while(temp!=NULL)
    {
        cout<<temp->data<<"  ";
        temp = temp->next;
    }
    cout<<endl;
}

bool isCircular(Node* &head){
    if(head == NULL)
        return true;
    Node* temp = head->next;
    while(temp != NULL && temp != head){
        temp = temp->next;
    }
    if(temp == head)
        return true;
    return false;
} 

bool detectLoop(Node* head){
    if(head == NULL)
    {
        return false;
    }
    map<Node*, bool> visited;
    Node* temp = head;
    while(temp != NULL){
        if(visited[temp] == true)
        {
            cout<<"Loop is present at element "<<temp->data<<endl;
            return 1;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    cout<<"No Loop Present..."<<endl;
    return false;
}

Node* floydDetectLoop(Node* head){
    if(head == NULL)
        return NULL;
    
    Node *fast = head;
    Node* slow = head;
    
    //After entering the loop, with each iteration, the distance between fast and slow gets smaller. 
    while(fast != NULL && slow != NULL)
    {
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
        if(fast == slow)
        {
            cout<<"Loop is present..."<<endl;
            return slow;
        }
    }
    cout<<"No Loop Present..."<<endl;
    return NULL;
}

//Distance between starting point to the node where the loop starts = from where the slow is pointing to, till the node where the loop starts
Node* getStartingLoopNode(Node* head){
    if(head == NULL)
        return NULL;
        
    Node* intersection = floydDetectLoop(head);
    
    if(intersection == NULL)
        return NULL;
    
    Node* start = head;
    while(start != intersection){
        start = start->next;
        intersection = intersection->next;
    }
    cout<<"Loop is present at Node with data -> "<<start->data<<endl;
    return start;
}

void removeLoop(Node *head){
    if(head == NULL)
        return;
        
    Node *startOfLoop = getStartingLoopNode(head);
    
    if(startOfLoop == NULL)
        return;
    
    Node *temp = startOfLoop;
    while(temp->next != startOfLoop){
        temp = temp->next;
    }
    cout<<"Loop is removed..."<<endl;
    temp->next =NULL;
}

int main(){
    //use of constructor
    Node *node1 = new Node(5);
    cout<<node1->data<<endl<<node1->next<<endl;
    
    Node *head = node1;
    Node *tail = node1;
    //insertion at head
    insertAtHead(head, 10);
    print(head);
    
    //insertion at tail
    insertAtTail(tail, 15);
    print(head);

    //insertion at 2nd position
    insertAtPosition(head, tail, 2, 20);
    print(head);

    //deleting the end node
    deleteNode(head, tail, 4);
    print(head);
    print(tail);

    cout<<"Length: "<<getLength(head)<<endl;

    cout<<"Is Linked List circular? - "<<isCircular(head);
    
    tail->next = head->next;
    
    detectLoop(head);
    
    //floydDetectLoop(head);
    //getStartingLoopNode(head);
    removeLoop(head);
}