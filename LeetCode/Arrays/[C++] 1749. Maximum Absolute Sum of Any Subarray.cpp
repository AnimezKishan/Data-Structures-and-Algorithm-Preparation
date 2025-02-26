// Kadane's Algorithm
// The key idea is the max absolute sum will be either the max sum or the min sum.

class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int n = nums.size();
            int maxEnding = nums[0];
            int maxSum = nums[0];
            for(int i=1; i<n; i++) {
                maxEnding = (maxEnding + nums[i] > nums[i]) ? maxEnding + nums[i] : nums[i];
    
                maxSum = max(maxSum, maxEnding);
            }
    
            int minEnding = nums[0];
            int minSum = nums[0];
            for(int i=1; i<n; i++) {
                minEnding = (minEnding + nums[i] < nums[i]) ? minEnding + nums[i] : nums[i];
    
                minSum = min(minSum, minEnding); 
            }
    
            // cout<<minSum<<" "<<maxSum;
            return max(abs(minSum), maxSum);
        }
    };