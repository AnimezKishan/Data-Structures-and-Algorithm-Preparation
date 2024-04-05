class Solution {
public:
    string makeGood(string s) {
        string ans;
        ans += s[0];

        for(int i=1;i<s.length();i++){
            // absolute difference of same Upper case and Lower case character is 32.
            if(ans.length() && abs(s[i] - ans.back()) == 32 )
                ans.pop_back();
            else
                ans += s[i];
        }

        return ans;
    }
};