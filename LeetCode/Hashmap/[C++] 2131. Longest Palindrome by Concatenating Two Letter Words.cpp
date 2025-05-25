class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int ans = 0;

        for(string &word : words) {
            mp[word]++;
        }

        bool notUsed = true;
        for(auto &[word, count] : mp) {
            string revStr = word;
            reverse(begin(revStr), end(revStr));
            
            if(word[0] == word[1]) {
                if(count == 1 && notUsed) {
                    ans += 2;
                    notUsed = false;
                }
                else {
                    if(count&1 && notUsed){
                        ans += count*2;
                        notUsed = false;
                    }
                    else if(count&1 && !notUsed) {
                        ans += (count-1)*2;
                    }
                    else {
                        ans += count*2;
                    }
                }
            }
            else if(mp.find(revStr) != mp.end()) {
                ans += min(count, mp[revStr])*2;
            }
        }

        return ans;
    }
};