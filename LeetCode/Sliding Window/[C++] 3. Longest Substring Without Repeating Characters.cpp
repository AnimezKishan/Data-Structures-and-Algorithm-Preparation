class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int j = 0, i = 0;
        int ans = 0;
        unordered_map<char, int> mp;
        while(j < s.length()) {
            mp[s[j]]++;

            while(mp[s[j]] > 1) {
                mp[s[i]]--;
                i++;
            }

            ans = max(ans, j-i+1);
            j++;
        }

        return ans;
    }
};