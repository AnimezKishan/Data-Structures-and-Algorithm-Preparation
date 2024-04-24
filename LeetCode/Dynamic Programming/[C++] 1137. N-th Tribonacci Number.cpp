// Approach I

class Solution {
public:
    int dp[38];
    int solve(int n){
        if(n == 0)
            return 0;
        
        if(n == 1 || n == 2)
            return 1;
        
        if(dp[n] != -1)
            return dp[n];
        
        return dp[n] = solve(n-1) + solve(n-2) + solve(n-3);
    }
    int tribonacci(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};


// Approach II
/*
class Solution {
public:
    int tribonacci(int n) {
        if(n == 0)
            return 0;
        
        if(n == 1 || n == 2)
            return 1;
        
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = dp[2] = 1;

        for(int i=3;i<=n;i++)
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        
        return dp[n];
    }
};
*/