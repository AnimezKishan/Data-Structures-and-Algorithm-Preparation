class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_map<string, bool> mp;
        for(auto &word : bannedWords)
            mp[word] = true;
        
        int count = 0;
        for(auto &word : message) {
            if(mp.find(word) != mp.end())
                count++;
            
            if(count >= 2)
                return true;
        }

        return false;
    }
};