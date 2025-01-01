// Prefix Sum

class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        vector<int> oneCount(n, 0);

        // store the one count from right to left
        oneCount[n-1] = s[n-1] == '1';
        for(int i=n-2; i>=0; i--) {
            oneCount[i] = oneCount[i+1] + (s[i] == '1');
        }
        
        int ans = 0, zeroCount = 0;
        for(int i=0; i<n-1; i++) {
            zeroCount += s[i] == '0';
            ans = max(ans, zeroCount + oneCount[i+1]);
        }

        return ans;
    }
};