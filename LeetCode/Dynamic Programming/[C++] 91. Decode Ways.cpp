class Solution {
public:
    int dp[101];
    int solve(int i, string &s, int &n){
        if(dp[i] != -1)
            return dp[i];
        
        if(i == n)
            return 1;
        
        if(s[i] == '0')
            return 0;
        
        int take_one_elem = 0;
        int take_two_elem = 0;

        take_one_elem += solve(i+1, s, n);
        
        if(i+1 < n)
            if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))
                take_two_elem += solve(i+2, s, n);
        
        return dp[i] = take_one_elem + take_two_elem;

    }
    int numDecodings(string s) {
        int n = s.length();
        memset(dp, -1, sizeof(dp));
        return solve(0, s, n);
    }
};