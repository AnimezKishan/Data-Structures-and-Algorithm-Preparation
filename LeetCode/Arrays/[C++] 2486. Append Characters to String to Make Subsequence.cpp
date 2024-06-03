// Two-Pointer

class Solution {
public:
    int appendCharacters(string s, string t) {
        int m = s.length(), n = t.length();
        int i = 0, j = 0;

        while(i < m && j < n){
            if(s[i] == t[j])
                j++;
            
            i++;
        }

        return n-j;
    }
};