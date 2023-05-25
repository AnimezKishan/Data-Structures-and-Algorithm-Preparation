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
};

void insertAtHead(Node* &head, int d){
    Node *temp=new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d)
{
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

void print(Node* &head){
    Node *temp = head;
    
    while(temp!=NULL)
    {
        cout<<temp->data<<"  ";
        temp = temp->next;
    }
    cout<<endl;
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
}