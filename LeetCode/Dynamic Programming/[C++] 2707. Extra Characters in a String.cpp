class Solution {
public:
    int n;
    unordered_set<string> st;

    //This helps to make every character of string as a starting character to continue searching with.
    int solve(int idx, string &s, vector<int> &dp){
        if(idx >= n)
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        int minExtra = n;
        string currStr = "";

        //This helps to check substrings after concatinating characters one by one.
        for(int i=idx;i<n;i++)
        {
            currStr.push_back(s[i]);

            int currExtra = (st.find(currStr) == st.end()) ? currStr.length() : 0;
            int nextExtra = solve(i+1, s, dp);
            int totalExtra = currExtra + nextExtra;

            minExtra = min(minExtra, totalExtra);
        }
        return dp[idx] = minExtra;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.length();
        vector<int> dp(n+1, -1);
        for(string &w:dictionary)
            st.insert(w);
        return solve(0, s, dp);
    }
};