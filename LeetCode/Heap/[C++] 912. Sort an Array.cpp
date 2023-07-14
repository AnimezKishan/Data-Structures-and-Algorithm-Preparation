/*
** HEAP SORT **
T.C -> O(n*log(n))
S.C -> O(1)
*/

class Solution {
public:
    void heapify(vector<int> &arr, int n, int i){
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;

        if(left < n && arr[largest] < arr[left])
            largest = left;
        
        if(right < n && arr[largest] < arr[right])
            largest = right;
        
        if(largest != i)
        {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }

    void heapSort(vector<int> &arr, int n)
    {
        //Convert array into max heap
        for(int i=n/2-1;i>=0;i--)
            heapify(arr, n, i);
        
        //Heap Sort Algo 
        for(int i=n-1;i>=0;i--)
        {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        heapSort(nums, nums.size());
        return nums;
    }
};