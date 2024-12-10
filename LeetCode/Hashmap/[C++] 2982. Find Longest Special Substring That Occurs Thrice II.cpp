class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();
        vector<vector<int>> mp(26, vector<int>(n+1, 0));

        int i = 0;
        while(i<n) {
            char ch = s[i];
            int len = 0;
            while(s[i] == ch) {
                len++;
                mp[ch - 'a'][len]++;
                i++;
            }
        }

        int ans = 0;

        for(int i=0; i<26; i++) {
            if(mp[i][n] >= 3)
                ans = max(ans, n);
            for(int j=n-1; j>0; j--) {
                mp[i][j] += mp[i][j+1];

                if(mp[i][j] >= 3)
                    ans = max(ans, j);
            }
        }

        return ans == 0 ? -1 : ans;
    }
};