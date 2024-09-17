class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        unordered_map<string, int> mp1, mp2;
        for(int i=0; i<n1; i++) {
            string word = "";
            while(i<n1 && s1[i] != ' '){
                word += s1[i];
                i++;
            }

            mp1[word]++;
        }

        for(int i=0; i<n2; i++) {
            string word = "";
            while(i<n2 && s2[i] != ' '){
                word += s2[i];
                i++;
            }

            mp2[word]++;
        }

        vector<string> ans;
        for(auto &i : mp1)
            if(mp1[i.first] == 1 && mp2.find(i.first) == mp2.end())
                ans.push_back(i.first);
        for(auto &i : mp2)
            if(mp2[i.first] == 1 && mp1.find(i.first) == mp1.end())
                ans.push_back(i.first);

        return ans;
    }
};