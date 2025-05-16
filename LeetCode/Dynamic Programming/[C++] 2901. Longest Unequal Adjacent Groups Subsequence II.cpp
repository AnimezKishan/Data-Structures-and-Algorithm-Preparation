// Bottom Up 
// LIS Varient

class Solution {
public:
    bool checkHammingDistOne(string &w1, string &w2) {
        int diff = 0;
        for(int i=0; i<w1.length(); i++) {
            if(w1[i] != w2[i])
                diff++;
            
            if(diff > 1)
                return false;
        }

        return true;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();

        vector<int> dp(n, 1);
        vector<int> prev(n, -1);

        int longestSubSeq = 1;
        int longestSubSeqIdx = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(groups[j] != groups[i] && words[j].length() == words[i].length() && checkHammingDistOne(words[i], words[j])) {

                    if(dp[j]+1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;

                        if(longestSubSeq < dp[i]) {
                            longestSubSeq = dp[i];
                            longestSubSeqIdx = i;
                        }
                    }
                }
            }
        }

        vector<string> ans;
        while(longestSubSeqIdx != -1) {
            ans.push_back(words[longestSubSeqIdx]);
            longestSubSeqIdx = prev[longestSubSeqIdx];
        }

        reverse(begin(ans), end(ans));
        return ans;
    }
};