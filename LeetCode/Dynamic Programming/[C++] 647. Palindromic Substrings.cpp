class Solution {
public:
    int n;
    int dp[1001][1001];
    bool checkP(string &s, int i, int j){
        if(i>j)
            return true;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] == s[j])
            return dp[i][j] = checkP(s, i+1, j-1);
        
        return dp[i][j] = false;
    }
    
    int countSubstrings(string s) {
        n = s.length();
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(checkP(s, i, j))
                    ans++;
            }
        }

        return ans;
    }
};