class Solution {
public:
    int N, M, K;
    int MOD = 1e9 + 7;

    // Memoization representation --> dp[index][searchCost][maxSoFar]
    int dp[51][51][101];

    int solve(int idx, int searchCost, int maxSoFar){
        if(idx == N){
            if(searchCost == K)
                return 1;
            return 0;
        }

        if(dp[idx][searchCost][maxSoFar] != -1)
            return dp[idx][searchCost][maxSoFar];

        int result = 0;

        for(int i=1;i<=M;i++){
            if(i > maxSoFar)
                result = (result + solve(idx+1, searchCost+1, i)) % MOD;
            else
                result = (result + solve(idx+1, searchCost, maxSoFar)) % MOD;
        }

        return dp[idx][searchCost][maxSoFar] = result % MOD;
    }
    int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;

        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0);
    }
};