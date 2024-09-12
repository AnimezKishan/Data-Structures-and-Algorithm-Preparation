class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, bool> mp;
        for(char &letter : allowed) 
            mp[letter] = true;
        
        int ans = 0;
        for(string &word : words) {

            bool flag = 0;
            for(char &letter : word) {
                if(mp.find(letter) == mp.end()){
                    flag = 1;
                    break;
                }
            }

            if(!flag)
                ans++;
        }

        return ans;
    }
};