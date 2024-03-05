// Two Pointer

class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        int i = 0;
        int j = n-1;
        char lastDel;

        while(i < j){
            if(s[i] == s[j]){
                lastDel = s[i];
                i++;
                j--;
            }

            else if(s[i] == lastDel)
                i++;
            
            else if(s[j] == lastDel)
                j--;
            
            else
                break;
        }

        // Edge Cases like "aaaaaaaaaaaaa"
        if(s[i] == lastDel)
            return 0;
        else
            return j-i+1;
    }
};