#include <bits/stdc++.h>
using namespace std;

class Node{
    
    public:
    Node *prev;
    int data;
    Node*next;
    
    //constructor
    Node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

//traversing the Linked list
void print(Node* &head){
    Node *temp = head;
    
    while(temp != NULL)
    {
        cout<<temp->data<<"  ";
        temp = temp->next;
    }
    cout<<endl;
}

//gives length of linked list
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
    
    Node *temp = new Node(d);
    head->prev = temp;
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d){
    //if passed tail is already empty.
    if(tail == NULL){
        Node *temp = new Node(d);
        tail = temp;
        return;
    }
    
    Node *temp =new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d){
    if (position == 1)
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
    
    while(cnt < position-1)
    {
        temp=temp->next;
        cnt++;
    }
    
    if(temp->next == NULL){
        insertAtTail(tail, d);
        return;
    }
    
    Node *nodeToInsert = new Node(d);
    nodeToInsert->prev = temp;
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    
}

int main()
{
    Node *node1 = new Node(5);
    Node *head = node1;
    Node *tail = node1;
    
    print(head);
    cout<<"Length: "<<getLength(head)<<endl;
    
    //inserting at head
    insertAtHead(head, 10);
    insertAtHead(head, 15);
    print(head);
    
    //inserting at tail
    insertAtTail(tail, 20);
    insertAtTail(tail, 25);
    print(head);
    
    //inserting at 4th and 5th position
    insertAtPosition(head, tail, 4, 30);
    insertAtPosition(head, tail, 5, 35);
    print(head);
    
    return 0;
}