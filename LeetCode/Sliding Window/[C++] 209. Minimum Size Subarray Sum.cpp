class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0, currSum = 0, ans = n+1;

        while(j<n){
            currSum += nums[j];

            while(currSum >= target) {
                ans = min(ans, j-i+1);
                currSum -= nums[i];
                i++;
            }
            
            j++;
        }

        return ans == n+1 ? 0 : ans;
    }
};