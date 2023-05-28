#include <bits/stdc++.h>
using namespace std;

class Node{
    
    public:
    int data;
    Node *next;
     
    //constructor
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
    
    //destructor
    ~Node(){
        int val = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory freed for node with value: "<<val<<endl;
    }
};

void insertNode(Node* &tail, int element, int d){
    //empty list
    if(tail == NULL){
        Node *temp = new Node(d);
        temp->next = temp;
        tail = temp;
        return;
    }
    //non-empty list
    else{
        Node *curr = tail;
        
        while(curr->data != element){
            curr = curr->next;
            if(curr == tail)
            {
                cout<<"Insertion not valid!"<<endl;
                return;
            }
        }
        
        //also works for the end position case
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void print(Node* &tail){
    Node *temp = tail;
    
    if(tail == NULL)
    {
        cout<<"List is empty..."<<endl;
        return;
    }
    //used do while to at least at execute one time for the single/first node.
    do {
        cout<<temp->data<<"  ";
        temp = temp->next;
    } while(temp != tail);
    
    cout<<endl;
}

void deleteNode(Node* &tail, int element){
    if(tail == NULL)
    {
        cout<<"List is empty, deletion not possible!"<<endl;
        return;
    }
    else{
        //assuming "element" is present in List
        Node *prev = tail;
        Node *curr = prev->next;
        
        while(curr->data != element)
        {
            prev = curr;
            curr = curr->next;
        }
        
        prev->next = curr->next;
        
        //1 node only
        if(prev == curr)
            tail = NULL;
            
        //>=2 nodes
        if(curr == tail)
            tail = prev;
            
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    Node *tail = NULL;
    
    //insertion in empty list
    //here, element parameter doesn't matter as the tail is NULL
    insertNode(tail, 4, 10);
    print(tail);
    
    //insert after element '10' and '20'
    insertNode(tail, 10, 20);
    insertNode(tail, 20, 30);
    insertNode(tail, 20, 40);
    print(tail);
    
    //deleting the element '40'
    deleteNode(tail, 10);
    print(tail);
    return 0;
}