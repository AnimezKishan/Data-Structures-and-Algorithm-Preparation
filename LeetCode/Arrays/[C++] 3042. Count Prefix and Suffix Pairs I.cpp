class Solution {
public:
    bool isPrefixAndSuffix(string &s1, string &s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        int i = 0, j = 0;
        while(i<n1) {
            if(j >= n2 || s1[i++] != s2[j++])
                return false;
        }

        i = 0, j = n2 - n1;
        while(i<n1) {
            if(j<0 || j>= n2 || s1[i++] != s2[j++])
                return false;
        }

        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();

        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                ans += isPrefixAndSuffix(words[i], words[j]);
            }
        }

        return ans;
    }
};