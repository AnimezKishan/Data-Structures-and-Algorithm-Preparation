/*
Approach for Follow Up
O(m*log(n))
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        map<char, vector<int>> mp;
        for(int i=0;i<n;i++)
            mp[t[i]].push_back(i);
        
        int prev = -1;
        for(int i=0;i<m;i++)
        {
            char ch = s[i];

            if(mp.find(ch) == mp.end())
                return false;
            
            vector<int> indices = mp[ch];

            auto it = upper_bound(begin(indices), end(indices), prev);

            if(it == indices.end())
                return false;
            
            prev = *it;
        }

        return true;
    }
};


//Two Pointer

/*
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();

        int i = 0, j = 0;
        while(i<m && j<n)
        {
            if(s[i] == t[j])
                i++;
            
            j++;
        }

        return i == m;
    }
};
*/