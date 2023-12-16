class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;

        vector<pair<int, int>> map(26);

        for(int i=0;i<s.size();i++){
            map[s[i]-'a'].first++;
            map[t[i]-'a'].second++;
        }

        for(int i=0;i<26;i++)
            if(map[i].first != map[i].second)
                return false;
        
        return true;
    }
};