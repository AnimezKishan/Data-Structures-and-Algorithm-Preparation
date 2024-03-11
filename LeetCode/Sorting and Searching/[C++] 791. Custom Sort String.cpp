// Sorting using Lambda [Comparator]

class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> m(26, INT_MAX);

        for(int i=0;i<order.length();i++){
            m[order[i]-'a'] = i;
        }

        auto lambda = [&](char &ch1, char &ch2){
            return m[ch1-'a'] < m[ch2-'a'];
        };

        sort(begin(s), end(s), lambda);
        return s;
    }
};


// Using Hash-Map
/*
class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> m(26, 0);

        for(char &i : s)
            m[i-'a']++;

        string ans = "";
        for(char &i : order){
            if(m[i-'a'] > 0){
                ans.append(m[i-'a'], i);
                m[i-'a'] = 0;
            }
        }

        for(int i = 0; i<26; i++){
            if(m[i] > 0)
                ans.append(m[i], char(i+'a'));
        }

        return ans;
    }
};
*/