class Solution {
public:
    int n;
    int dp[2501][2501];
    int solve(int i, vector<int> &nums, int prev){
        if(i==n)
            return 0;

        if(prev != -1 && dp[i][prev] != -1)
            return dp[i][prev];

        int take = 0;
        if(prev == -1 || nums[i] > nums[prev])
            take = 1+solve(i+1, nums, i);

        int leave = solve(i+1, nums, prev);

        if(prev != -1)
            dp[i][prev] = max(take, leave);

        return max(take, leave);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, nums, -1);
    }
};