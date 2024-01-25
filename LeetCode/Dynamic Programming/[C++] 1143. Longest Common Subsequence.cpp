class Solution {
public:
    int m, n;
    int ans = INT_MIN;
    int dp[1001][1001];

    int solve(int i, int j, string &s1, string &s2){
        if(i >= m || j >= n)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s1[i] == s2[j])
            return dp[i][j] = 1 + solve(i+1, j+1, s1, s2);
        else{
            return dp[i][j] = max(solve(i, j+1, s1, s2), solve(i+1, j, s1, s2));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        m = text1.length();
        n = text2.length();
        memset(dp, -1, sizeof(dp));

        return solve(0, 0, text1, text2);

    }
};