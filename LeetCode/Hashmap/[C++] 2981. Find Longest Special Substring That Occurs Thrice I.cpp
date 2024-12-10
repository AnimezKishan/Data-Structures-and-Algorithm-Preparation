class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();
        map<pair<char, int>, int> mp;

        for(int i=0; i<n; i++) {
            char ch = s[i];
            int len = 0;
            for(int j=i; j<n; j++) {
                if(ch == s[j]){
                    len++;
                    mp[{ch, len}]++;
                }
                else
                    break;
            }
        }

        int ans = -1; 
        for(auto &i : mp) {
            int len = i.first.second;
            int freq = i.second;

            if(freq >= 3 && len > ans)
                ans = len;
        }

        return ans;
    }
};