// Top Down
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


// Bottom Up
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1);
        int longestSubSeq = 1;

        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[i] > nums[j] && dp[j]+1 > dp[i]) {
                    dp[i] = dp[j]+1;

                    if(longestSubSeq < dp[i])
                        longestSubSeq = dp[i];
                }
            }
        }

        return longestSubSeq;
    }
};