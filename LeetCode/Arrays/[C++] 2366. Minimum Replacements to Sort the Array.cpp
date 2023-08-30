class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n=nums.size();

        long long ans = 0;

        //start with last index
        int curr_min = nums[n-1];

        for(int i=n-2;i>=0;i--)
        {
            //if the number is greater, break it into possible no. of steps
            if(nums[i] > curr_min)
            {
                /*
                no. of steps to break it
                ceil helps to to keep the value in bound
                ex - 9/2.0 => ceil(4.5) => 5
                */
                int steps = ceil(nums[i] / (1.0 * curr_min)) - 1;
                ans += steps;

                /*
                after the steps applied, it checks if any no. is smaller than current minimum after operation
                ex - if 9 is breaked into 4 steps for minimum = 2
                9 => 1,8 => 1,2,6 => 1,2,2,4 => 1,2,2,2,2
                after this, minimum should be changed as 1.
                */
                curr_min = min(curr_min, nums[i] / (steps+1));
            }
            else
            {
                curr_min = nums[i];
            }
        }
        return ans;
    }
};