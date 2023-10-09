class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, last = -1;
        int s = 0, e = nums.size() - 1;
        int mid;

        //searching the left part of the array for first occurance
        while(s<=e){
            mid = s+(e-s)/2;
            if(nums[mid] == target)
                first = mid;
            if(nums[mid] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }

        if(first == -1)
            return {first, last};
        else
            s = first;
        
        //if the first occurance found, searching for the last occurance of it.
        e=nums.size()-1;
        mid=s+(e-s)/2;
        while(s<=e){
            if(nums[mid] == target)
                last=mid;
            if(target <nums[mid])
                e=mid-1;
            else
                s=mid+1;
            mid=s+(e-s)/2;
        }
        return {first, last};
    }
};