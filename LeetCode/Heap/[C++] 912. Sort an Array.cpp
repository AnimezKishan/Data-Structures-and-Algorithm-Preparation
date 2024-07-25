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


// Counting Sort
/*
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int minElem = *min_element(begin(nums), end(nums));
        int maxElem = *max_element(begin(nums), end(nums));

        unordered_map<int, int> mp;

        for(int &num:nums)
            mp[num]++;

        int idx = 0;
        for(int i=minElem; i<=maxElem; i++){
            while(mp[i]){
                nums[idx++] = i;
                mp[i]--;
            }
        }

        return nums;
    }
};
*/


// Quick Sort [gives TLE because of not selecting pivot randomly]
/*
-> We take a element as pivot and set it's correct position in which:
    -> we place all elements less than pivot element left to it.
    -> we place all elements greater than pivot element right to it.
-> Then we do the same thing recursively for the left and right part.

Core of Quick Sort is -> Place a pivot element into it's correct position at a time.
*/
/*
class Solution {
public:
    void quickSort(vector<int> &nums, int low, int high) {
        if(low >= high) {
            return;
        }
        
        int pivotIndex = partition(nums, low, high);
        
        quickSort(nums, low, pivotIndex-1);
        quickSort(nums, pivotIndex+1, high);
    }
    
    public:
    int partition (vector<int> &nums, int low, int high) {
        int pivot = nums[high];
        int pivotIndex = low;
        
        for(int i = low; i < high; i++) {
            if(nums[i] <= pivot) {
                swap(nums[i], nums[pivotIndex]);
                pivotIndex++;
            }
        }
        
        swap(nums[pivotIndex], nums[high]);
        
        return pivotIndex;
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};
*/