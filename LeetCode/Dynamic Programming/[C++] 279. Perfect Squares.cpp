class Solution {
public:
    int dp[10001];

    int solve(int n){
        if(n == 0)
            return 0;
        
        if(dp[n] != -1)
            return dp[n];
        
        int ans = INT_MAX;
        
        for(int i=1;i<=sqrt(n);i++){
            int square = i*i;
            int ways = 1 + solve(n-square);
            ans = min(ans, ways);
        }

        return dp[n] = ans;
    }
    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};