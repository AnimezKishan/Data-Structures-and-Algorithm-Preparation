class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> lastOccur(26, -1);

        int ans = -1;
        for(int i=0;i<s.length();i++){
            int ch = s[i]-'a';

            if(lastOccur[ch] == -1){
                lastOccur[ch] = i;
            }
            else{
                ans = max(ans, (i-lastOccur[ch]-1));
            }
        }

        return ans;
    }
};