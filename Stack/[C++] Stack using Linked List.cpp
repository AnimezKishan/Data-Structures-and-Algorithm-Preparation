#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};

class Stack{
    public:
    int size;
    Node* head;
    
    Stack(int size){
        this->size = size;
        this->head = NULL;
    }
    
    void Size()
    {
        cout<<"Size of stack: "<<this->size<<endl;
    }
    
    void push(int d)
    {
        int cnt;
        Node* temp = head;
        while(temp != NULL)
        {
            temp = temp->next;
            cnt++;
        }
        if(cnt<size)
        {
            Node* toInsert = new Node(d);
            if(head == NULL)
            {
                cout<<"Element pushed: "<<toInsert->data<<endl;
                head = toInsert;
                return;
            }
            else{
                cout<<"Element pushed: "<<toInsert->data<<endl;
                toInsert->next = head;
                head = toInsert;
            }
        }
        else
            cout<<"Stack Overflow!"<<endl;
    }
    
    void pop(){
        if(head == NULL)
        {
            cout<<"Stack Underflow!"<<endl;
            return;
        }
        Node* toDelete = head;
        cout<<"Element poped: "<<toDelete->data<<endl;
        head = head->next;
        delete toDelete;
    }
    
    void top()
    {
        if(head == NULL)
        {
            cout<<"Stack is Empty!"<<endl;
            return;
        }
        cout<<"Top element of stack: "<<head->data<<endl;
    }
    
    bool isEmpty()
    {
        if(head == NULL)
            return true;
        else
            return false;
    }
};

int main()
{
    Stack s(5);
    s.Size();
    
    s.push(6);
    s.push(7);
    s.top();
    
    s.pop();
    s.top();
    
    
    s.push(8);
    s.push(9);
    s.push(10);
    cout<<endl<<"Is stack is Empty? - "<<s.isEmpty();
    return 0;
}
