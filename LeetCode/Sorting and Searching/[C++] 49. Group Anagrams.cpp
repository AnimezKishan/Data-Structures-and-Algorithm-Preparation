class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            sort(begin(s), end(s));
            mp[s].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(auto &i:mp){
            ans.push_back(i.second);
        }

        return ans;
    }
};

// Without Sorting
/*
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            vector<int> count(26, 0);

            for(int j=0;j<s.length();j++){
                count[s[j]-'a']++;
            }

            string map_word = "";
            for(int i=0;i<26;i++){
                int freq = count[i];
                if(freq > 0)
                    map_word += string(freq, i+'a');
            }

            mp[map_word].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(auto &i:mp)
            ans.push_back(i.second);
        
        return ans;
    }
};
*/