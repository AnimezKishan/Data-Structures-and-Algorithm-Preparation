// LIS Varient

class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(string &s, int idx, int prev, int &k){
        if(idx >= n)
            return 0;

        if(dp[idx][prev] != -1)
            return dp[idx][prev];
        
        int take = 0;
        int ch = s[idx] - 'a' + 1;

        if(prev == 0 || abs(prev - ch) <= k)
            take = 1 + solve(s, idx+1, ch, k); 
        
        int notTake = solve(s, idx+1, prev, k);

        return dp[idx][prev] = max(take, notTake); 
    }
    int longestIdealString(string s, int k) {
        n = s.size();
        dp.resize(n, vector<int>(27, -1));

        return solve(s, 0, 0, k);
    }
};