// T.C -> O(n*log(n))
// S.C -> O(log(n)) 
// [ No extra space is needed apart from a few variables. However, some space is required for sorting. In C++ sort() function provided by STL is a hybrid of Quick Sort, Heap Sort, and Insertion Sort and has a worst-case space complexity of O(log⁡⁡⁡N) ] 

class Solution {
public:
    int j;
    int solve(vector<int> &nums, int val) {
        int s = 0, e = j;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(nums[mid] >= val)
                e = mid-1;
            else
                s = mid+1;
        }

        return s;
    }
    int specialArray(vector<int>& nums) {
        int n = *max_element(begin(nums), end(nums));

        sort(begin(nums), end(nums));

        j = nums.size()-1;
        for(int val=0;val<=n;val++){
            int i = solve(nums, val);
            if((j-i+1) == val)
                return val;
        }

        return -1;
    }
};