/*
T.C -> O(n)
S.C -> O(n)
*/

class Solution {
public:
    int minDeletions(string s) {
        vector<int> map(26, 0);
        for(auto i:s)
            map[i-'a']++;
        
        int change = 0;
        for(int i=0;i<26;i++)
        {
            if(map[i] > 0 && (count(map.begin(), map.end(), map[i]) > 1))
            {
                map[i]--;
                i--;
                change++;
            }
        }
        
        return change;
    }
};