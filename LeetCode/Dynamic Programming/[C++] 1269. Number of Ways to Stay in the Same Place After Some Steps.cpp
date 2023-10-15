class Solution {
public:
    int dp[501][501];
    int MOD = 1e9 + 7;
    int solve(int curr_idx, int curr_step, int steps, int arr_len){
        if(curr_idx < 0 || curr_idx >= arr_len)
            return 0;
        
        if(curr_step > steps)
            return 0;

        if(dp[curr_idx][curr_step] != -1)
            return dp[curr_idx][curr_step];
        
        if(curr_idx == 0 && curr_step == steps)
            return 1;
        
        //right
        int result = (solve(curr_idx+1, curr_step+1, steps, arr_len)) % MOD;
        //stay
        result = (result + solve(curr_idx, curr_step+1, steps, arr_len)) % MOD;
        //left
        result = (result + solve(curr_idx-1, curr_step+1, steps, arr_len)) % MOD;

        return dp[curr_idx][curr_step] = result % MOD;
    }

    int numWays(int steps, int arrLen) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, steps, arrLen);
    }
}; 