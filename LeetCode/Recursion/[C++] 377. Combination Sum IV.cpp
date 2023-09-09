class Solution {
public:
    int n;
    int dp[201][1001];
    int solve(int idx, int target, vector<int>& nums)
    {
        if(target == 0)
            return 1;

        if(idx >= n || target < 0)
            return 0;
        
        if(dp[idx][target] != -1)
            return dp[idx][target];

        //start with zero index and check for all possibilities (Also does backtracking).
        int take_idx = solve(0, target-nums[idx], nums);
        //move to next index.
        int reject_idx = solve(idx+1, target, nums);

        return dp[idx][target] = take_idx + reject_idx;
    }
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();

        //Intializing Memo array with -1.
        memset(dp, -1, sizeof(dp));

        return solve(0, target, nums);
    }
};