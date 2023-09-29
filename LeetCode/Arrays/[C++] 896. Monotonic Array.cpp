class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool increasing = false;

        if(nums[0] < nums[n-1])
            increasing  = true;
        
        if(increasing)
        {
            for(int i=0;i<n-1;i++)
            {
                if(nums[i]>nums[i+1])
                    return false;
            }
        }
        else
        {
            for(int i=0;i<n-1;i++)
            {
                if(nums[i] < nums[i+1])
                    return false;
            }
        }

        return true;
    }
};