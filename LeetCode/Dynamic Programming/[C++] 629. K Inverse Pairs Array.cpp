// Also Go through - Triangle of Mahonian Numbers
 
class Solution {
public:
    int MOD = 1e9 +7;
    int dp[1001][1001];
    int solve(int n, int k){
        if(n==0)
            return 0;

        // only one sorted array would be possible for case k=0.
        if(k==0)
            return 1;
        
        if(dp[n][k] != -1)
            return dp[n][k];
        
        int ans = 0;
        // For n numbers, at most n-1 inversions could be possible.
        for(int inv = 0;inv<=min(k, n-1);inv++)
            // since current function has come up with 'inv' inversions, so the child recursive function should come up with k-inv inversions.
            ans = (ans + solve(n-1, k-inv))%MOD;
        
        return dp[n][k] = ans%MOD;
    }
    int kInversePairs(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(n, k);
    }
};