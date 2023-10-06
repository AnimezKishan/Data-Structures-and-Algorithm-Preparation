class Solution {
public:
    int dp[59];

    int solve(int n){
        if(n == 1)
            return 1;
        
        if(dp[n] != -1)
            return dp[n];
        
        int ans = INT_MIN;
        for(int i=1;i<=n-1;i++)
        {
            int prod = i * max(n-i, solve(n-i));
            ans = max(ans, prod);
        }

        return dp[n] = ans;
    }
    int integerBreak(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};