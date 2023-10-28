class Solution {
public:
    vector<vector<long long>> dp;
    int a = 0, e = 1, i = 2, o = 3, u = 4; 
    int MOD = 1e9 + 7;

    long long solve(int ch, int n){
        if(n == 0){
            return 1;
        }

        if(dp[ch][n] != -1)
            return dp[ch][n];

        if(ch == a)
            return dp[ch][n] = solve(e, n-1) % MOD;
        
        if(ch == e){
            return dp[ch][n] = (solve(a, n-1) + solve(i, n-1)) % MOD;
        }

        if(ch == i){
            return dp[ch][n] = (solve(a, n-1) + solve(e, n-1) + solve(o, n-1) + solve(u, n-1)) % MOD;
        }

        if(ch == o){
            return dp[ch][n] = (solve(i, n-1) + solve(u, n-1)) % MOD;
        }

        if(ch == u)
            return dp[ch][n] = solve(a, n-1) % MOD;
        
        return dp[ch][n] = 0;
    }
    int countVowelPermutation(int n) {
        long long ans = 0;

        dp.resize(5, vector<long long>(n+1, -1));

        ans = (ans + solve(a, n-1)) % MOD;
        ans = (ans + solve(e, n-1)) % MOD;
        ans = (ans + solve(i, n-1)) % MOD;
        ans = (ans + solve(o, n-1)) % MOD;
        ans = (ans + solve(u, n-1)) % MOD;

        return ans;
    }
};