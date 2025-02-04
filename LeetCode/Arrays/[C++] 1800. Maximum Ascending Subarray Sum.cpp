class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = nums[0], currSum = nums[0];

        for(int i=1; i<nums.size(); i++) {
            if(nums[i] > nums[i-1]) {
                currSum += nums[i];
                maxSum = max(maxSum, currSum);
            }
            else
                currSum = nums[i];
        }

        return maxSum;
    }
};