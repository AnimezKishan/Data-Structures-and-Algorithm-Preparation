class Solution {
public:
    int dp[31][1001];
    int MOD = 1e9 +7;
    int solve(int n, int k, int target){
        if(n == 0)
            return target == 0;
        
        if(target < 0)
            return 0;

        if(dp[n][target] != -1)
            return dp[n][target];

        int ans = 0;
        for(int face = 1;face<=k;face++){
            ans = (ans + solve(n-1, k, target-face)) % MOD;
        }

        return dp[n][target] = ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(n, k, target);
    }
};