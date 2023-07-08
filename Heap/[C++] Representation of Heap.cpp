#include <iostream>
using namespace std;

// MAX HEAP
class heap {
    public:
    int arr[100];
    int size;
    
    heap(){
        arr[0] = -1;
        size = 0;
    }
    
    //T.C -> O(log(n))
    void insert(int val){
        size++;
        int index = size;
        //1. insert the value
        arr[index] = val;
        
        //2. take value to its correct position by swapping the values if needed.
        while(index > 1)
        {
            int parent = index/2;
            
            if(arr[parent] < arr[index]){
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    
    void print()
    {
        cout<<"Printing Heap: "<<endl;
        for(int i=1;i<=size;i++){
            cout<< arr[i] <<" ";
        }
        cout<<endl;
    }
    
    void deleteFromHeap()
    {
        if(size == 0)
        {
            cout<<"Nothing to delete..."<<endl;
            return;
        }
        
        //1. Make the root node as last node.
        arr[1] = arr[size];
        
        //2. remove last element.
        size--;
        
        //3. take root node to its correct position.
        int i = 1;
        while(i < size)
        {
            //index of left child node is 2 times of parent node's index
            int leftIndex = 2*i;
            //index of right child node is 2 times of parent node's index + 1
            int rightIndex = 2*i+1;
            
            if(leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
                
            }
            
            else if(rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
                
            }
            
            else
                return;
        }
        
    }
};

// T.C -> O(log(n)) [for single call of function] 
void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;
    
    if(left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    
    if(right < n && arr[largest] < arr[right])
    {
        largest = right;
    }
    
    if(largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
    
    
    
}

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deleteFromHeap();
    h.print();

    int a[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    
    // Elements from (N/2)+1 -> n [these are leaf nodes] are already at there correct place. Heapify only for parent nodes. 
    for(int i = n/2;i>0;i--){
        //Here, as the fuction is called multiple times, T.C -> O(n) 
        heapify(a, n, i);
    }
    
    cout<<"Printing Heap: "<<endl;
    for(int i=1;i<=n;i++){
        cout<< a[i] <<" ";
    }
    cout<<endl;
    return 0;
}
