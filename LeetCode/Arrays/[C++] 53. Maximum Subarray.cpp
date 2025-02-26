// Kadane's Algorithm

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int ans = nums[0];
            int maxEnding = nums[0];
    
            for(int i=1; i<nums.size(); i++) {
                maxEnding = (maxEnding + nums[i] > nums[i]) ? maxEnding +  nums[i] : nums[i];
    
                ans = max(ans, maxEnding);
            }
    
            return ans;
        }
    };