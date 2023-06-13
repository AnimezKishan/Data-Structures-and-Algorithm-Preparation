#include <iostream>
using namespace std;

class Node{
    public: 
    int data;
    Node *next;
    
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};

class Queue{
    public:
    int size;
    int cnt = 0;
    Node* head;
    Node* tail;
    
    Queue(int s)
    {
        this->size = s;
        this->head = NULL;
        this->tail = NULL;
    }
    
    void Size(){
        cout<<"Size of Queue: "<<this->size<<endl;
    }
    
    void enQueue(int d)
    {
        if(cnt < size)
        {
            Node* temp = new Node(d);
            if(tail == NULL)
            {
                head = tail = temp;
                cout<<head->data<<" inserted successfully!"<<endl;
                cnt++;
                return;
            }
            
            tail->next = temp;
            cnt++;
            tail = temp;
            cout<<tail->data<<" inserted successfully!"<<endl;
        }
        else
        {
            cout<<"Queue OverFlow!"<<endl;
        }
        
    }
    
    void deQueue(){
        if(cnt > 0)
        {
            Node* temp = head;
            cout<<temp->data<<" dequeued successfully!"<<endl;
            head = head->next;
            
            if(head == NULL)
                tail = NULL;
            cnt--;
            delete (temp);
        }
        else
        {
            cout<<"Queue UnderFlow!"<<endl;
        }
    }
    
    bool isEmpty(){
        if(head == NULL)
        {
            return true;
        }
        return false;
    }
    
    void print(){
        if(head == NULL)
            return;
        Node *temp = head;
        cout<<"Queue Elements -> ";
        while(temp != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    
    void qFront(){
        cout<<"Queue Front: "<<head->data<<endl;
    }
    
    void qRear(){
        cout<<"Queue Rear: "<<tail->data<<endl;
    }
};

int main()
{
    Queue q(3);
    q.Size();
    
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    
    cout<<endl;
    q.print();
    
    cout<<endl;
    q.qFront();
    q.qRear();
    
    cout<<endl;
    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.deQueue();
    
    cout<<endl;
    cout<<"Queue Empty: "<<q.isEmpty();
    return 0;
}
