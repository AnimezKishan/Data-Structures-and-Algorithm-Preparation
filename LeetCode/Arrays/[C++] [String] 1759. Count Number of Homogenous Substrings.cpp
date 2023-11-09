class Solution {
public:
    int MOD = 1e9 + 7;
    int countHomogenous(string s) {
        int ans = 0;
        int len = 1;

        for(int i=0;i<s.length();i++){
            if(i>0 && s[i] == s[i-1])
                len++;
            else
                len = 1;
            
            ans = (ans + len)%MOD;
        }

        return ans;
    }
};