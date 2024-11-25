#include <iostream>
using namespace std;
class kQueue{
    public:
    int *arr;
    int n, k;
    int *front, *rear, *next;
    int freespot;
    
    kQueue(int n,int k){
        this->n = n;
        this->k = k;
        arr = new int[n];
        front = new int[k];
        rear =  new int[k];
        for(int i=0;i<k;i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }
        
        next = new int[n];
        for(int i=0;i<n;i++)
        {
            next[i] = i+1;
        }
        next[n-1] = -1;
        
        freespot = 0;
    }
    
    void enqueue(int data, int qn){
        //overflow
        if(freespot == -1)
        {
            cout<<"No Empty space is present."<<endl;
            return;
        }
        
        //find index
        int index = freespot;
        
        //update freespot
        freespot = next[index];
        
        //check whether if it's a first element
        if(front[qn-1] == -1)
            front[qn-1] = index;
        else
        {
            //link new element to previous element
            next[rear[qn-1]] = index;
        }
        
        //update next
        next[index] = -1;
        
        //update rear
        rear[qn-1] = index;
        
        //push element
        arr[index] = data;
        
        cout<<arr[index]<<" enqueued successfully"<<endl;
    }
    
    void dequeue(int qn){
        //underflow
        if(front[qn-1] == -1)
        {
            cout<<"Queue "<<qn<<" is Empty."<<endl;
            return;
        }
        
        //find index to pop
        int index = front[qn-1];
        
        //move front
        front[qn-1] = next[index];
        
        next[index] = freespot;
        freespot = index;
        
        cout<<"Element "<<arr[index]<<" dequeued."<<endl;
    }
};

int main()
{
    kQueue q(6, 3);
    q.enqueue(10, 1);
    q.enqueue(20, 1);
    
    q.enqueue(30, 2);
    q.enqueue(40, 2);
    
    q.enqueue(50, 3);
    q.enqueue(60, 3);
    q.enqueue(70, 3);
    
    q.dequeue(1);
    q.dequeue(1);
    q.dequeue(1);
    
    return 0;
}
