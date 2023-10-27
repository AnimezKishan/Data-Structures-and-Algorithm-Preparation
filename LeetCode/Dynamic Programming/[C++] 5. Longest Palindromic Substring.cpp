class Solution {
public:
    int dp[1001][1001];
    bool solve(string &s, int i, int j){
        if(i >= j)
            return true;

        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == s[j])
            return dp[i][j] = solve(s, i+1, j-1);
        
        return dp[i][j] = false;
    }

    string longestPalindrome(string s) {
        int n = s.length();

        int maxLen = INT_MIN;
        int startIndex = 0;

        memset(dp, -1, sizeof(dp));

        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                if(solve(s, i, j)){
                    if((j-i+1) > maxLen){
                        startIndex = i;
                        maxLen = j-i+1;
                    }
                }
            }
        }

        return s.substr(startIndex, maxLen);
    }
};