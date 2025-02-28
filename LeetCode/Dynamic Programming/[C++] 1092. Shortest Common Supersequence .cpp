/*
First, find the longest common subsequence string

Then, You can use two pointers p1 and p2 for str1 and str2, respectively.
For each LCS character, append str1[p1] to the answer while str1[p1] differs from the current LCS character and do the same for str2[p2].
Once str1[p1] and str2[p2] match the current LCS character, append it only once to the answer.
*/

class Solution {
    public:
        string shortestCommonSupersequence(string s1, string s2) {
            
            int m = s1.length();
            int n = s2.length();
            
            vector<vector<int>> dp(m+1, vector<int>(n+1));
            
            for(int i = 0; i<m+1; i++) {
                for(int j = 0; j < n+1; j++) {
                    if(i == 0 || j == 0)
                        dp[i][j] = i+j;
                    else if(s1[i-1] == s2[j-1])
                        dp[i][j] = 1 + dp[i-1][j-1];
                    else
                        dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
                }
            }
                    
            string scs = "";
            int i = m,  j = n;
            while(i > 0 && j > 0) {
                if(s1[i-1] == s2[j-1]) {
                    scs.push_back(s1[i-1]);
                    i--;
                    j--;
                } else {
                    if(dp[i-1][j] < dp[i][j-1]) {
                        scs.push_back(s1[i-1]);
                        i--;
                    } else {
                        scs.push_back(s2[j-1]);
                        j--;
                    }
                }
            }
    
            //add remaining characters from both s1 and s2
            while(i > 0) {
                scs.push_back(s1[i-1]);
                i--;
            }
            while(j > 0) {
                scs.push_back(s2[j-1]);
                j--;
            }
            reverse(scs.begin(), scs.end());
            
            return scs;
        }
    };