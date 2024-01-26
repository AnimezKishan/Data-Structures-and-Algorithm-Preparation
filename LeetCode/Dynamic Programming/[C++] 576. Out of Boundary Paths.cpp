class Solution {
public:
    int ans = 0;
    int MOD = 1e9 + 7;
    int dp[51][51][51];
    int solve(int m, int n, int maxMove, int i, int j){
        
        if(i < 0 || i == m || j < 0 || j == n)
            return 1;

        if(maxMove <= 0)
            return 0;

        if(dp[i][j][maxMove] != -1)
            return dp[i][j][maxMove]%MOD;
        
        dp[i][j][maxMove] = ((solve(m, n, maxMove-1, i, j-1) % MOD + solve(m, n, maxMove-1, i-1, j) % MOD) % MOD + (solve(m, n, maxMove-1, i, j+1) % MOD + solve(m, n, maxMove-1, i+1, j) % MOD) % MOD) % MOD;

        return dp[i][j][maxMove]%MOD;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return solve(m, n, maxMove, startRow, startColumn);
    }
};