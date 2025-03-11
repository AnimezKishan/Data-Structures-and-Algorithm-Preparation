// Similar to Leetcode 3306

class Solution {
    public:
        int numberOfSubstrings(string s) {
            int n = s.length();
            vector<int> freq(3, 0);
    
            int i = 0, j = 0, ans = 0;
            while(j < n) {
                char ch = s[j];
                freq[ch-'a']++;
    
                while(freq[0] && freq[1] && freq[2]) {
                    freq[s[i]-'a']--;
                    ans += (n - j);
                    i++;
                }
    
                j++;
            }
    
            return ans;
        }
    };