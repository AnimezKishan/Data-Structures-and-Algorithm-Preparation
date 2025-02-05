// Hashmap

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2)
            return true;

        int swapNeeded = 0;
        vector<int> s1Elems(26, 0), s2Elems(26, 0);
        for(int i=0; i<s1.length(); i++) {
            if(swapNeeded > 2)
                return false;
            if(s1[i] != s2[i])
                swapNeeded++;

            s1Elems[s1[i] - 'a']++;
            s2Elems[s2[i] - 'a']++;
        }

        for(int i=0; i<26; i++) {
            if(s1Elems[i] != s2Elems[i])
                return false;
        }

        return swapNeeded != 1 && swapNeeded <= 2;
    }
};