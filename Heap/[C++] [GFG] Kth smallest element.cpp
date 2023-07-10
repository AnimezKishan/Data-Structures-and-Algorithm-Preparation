class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    
    /*
    -> Insert first k elements in a max heap i.e 0 --> k-1
    -> After (k-1)th element, check for every iterated value if it is smaller than root element
        -> If yes, pop root element and place the iterated value in right place
        
    -> Now root node would be the kth smallest element. 
    */
    
    /*
    T.C -> O(k + (n-k)*log(k))
    S.c -> O(k)
    */
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        priority_queue<int> max_heap;
        
        //Step 1
        for(int i=0;i<k;i++)
        {
            max_heap.push(arr[i]);
        }
        
        //Step 2
        for(int i=k;i<=r;i++)
        {
            if(arr[i] < max_heap.top())
            {
                max_heap.pop();
                max_heap.push(arr[i]);
            }
        }
        
        //Step 3
        return max_heap.top();
    }
};