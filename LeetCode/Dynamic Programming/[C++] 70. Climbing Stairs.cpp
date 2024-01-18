//Top-Down Approach [Recursion + Memoization]

class Solution {
public:
    int dp[46];
    int solve(int n)
    {
        if(n<0)
            return 0;
        
        if(n == 0)
            return 1;
        
        if(dp[n] != -1)
            return dp[n];

        int oneStair = 0, twoStair = 0;

        oneStair = solve(n-1);
        twoStair = solve(n-2);

        return dp[n] = oneStair + twoStair;
    }

    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};