class Solution {
public:
    int n;
    int dp[101];
    int solve(int i, vector<int> &nums){
        if(i == 0)
            return nums[0];
        if(i < 0)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
            
        int take = 0, leave = 0;
        take = nums[i] + solve(i-2, nums);
        leave = 0 + solve(i-1, nums);

        return dp[i] = max(take, leave);
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(n-1, nums);
    }
};