class Solution {
public:
    int dp[1001][1001];
    int m; // length of target string 
    int k; // length of each string
    const int MOD = 1e9 + 7;
    int solve(int idx, int colIdx, string &target, vector<vector<long long>> &freq) {
        if(idx == m)
            return 1;
        
        if(colIdx == k)
            return 0;

        if(dp[idx][colIdx] != -1)
            return dp[idx][colIdx];
        
        int not_take = solve(idx, colIdx+1, target, freq)%MOD;
        int take = (freq[target[idx]-'a'][colIdx] * solve(idx+1, colIdx+1, target, freq))%MOD;

        return dp[idx][colIdx] = (take + not_take)%MOD;
    }
    int numWays(vector<string>& words, string target) {
        m = target.length();
        k = words[0].length();
        memset(dp, -1, sizeof(dp));

        vector<vector<long long>> freq(26, vector<long long>(k, 0));
        for(int col=0; col<k; col++) {
            for(string &word : words)
                freq[word[col]-'a'][col]++;
        }

        return solve(0, 0, target, freq);
    }
};