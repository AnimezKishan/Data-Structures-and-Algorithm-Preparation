class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), counter = 0;
        for(int i=1; i<n; i++)
            if(nums[i] < nums[i-1])
                counter++;

        if(nums[n-1] > nums[0])
            counter++;

        return counter <= 1;
    }
};