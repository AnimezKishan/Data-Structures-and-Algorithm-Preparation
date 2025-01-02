// Prefix Sum

class Solution {
public:
    bool isVowel(char &first, char &last) {
        if(first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u')
            if(last == 'a' || last == 'e' || last == 'i' || last == 'o' || last == 'u')
                return true;
        
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefixCount(n, 0);
        prefixCount[0] = isVowel(words[0][0], words[0][words[0].length() - 1]);

        for(int i=1; i<n; i++) 
            prefixCount[i] = isVowel(words[i][0], words[i][words[i].length() - 1]) + prefixCount[i-1];
        
        vector<int> ans;
        for(vector<int> &query : queries) {
            int l = query[0];
            int r = query[1];

            ans.push_back(prefixCount[r] - (l > 0 ? prefixCount[l-1] : 0));
        }
        
        return ans;

    }
};