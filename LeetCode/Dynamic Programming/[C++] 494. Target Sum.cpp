class Solution {
public:
    int T;
    int dp[21][2001];
    int solve(int idx, int currSum, vector<int> &nums) {
        if(idx == nums.size())
            if(currSum == T)
                return 1;
            else
                return 0;
        
        if(dp[idx][1000 + currSum] != -1)
            return dp[idx][1000 + currSum];

        int negative = solve(idx+1, currSum - nums[idx], nums);
        int positive = solve(idx+1, currSum + nums[idx], nums);

        return dp[idx][1000 + currSum] = negative + positive;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        T = target;
        memset(dp, -1, sizeof(dp));

        return solve(0, 0, nums);
    }
};