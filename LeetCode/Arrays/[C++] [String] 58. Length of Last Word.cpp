class Solution {
public:
    int lengthOfLastWord(string s) {
        bool spaceBeforeWord = false;
        int ans = 0;
        for(int i=s.length()-1;i>=0;i--){
            if(!spaceBeforeWord && s[i] == ' ')
                continue;
            else if(spaceBeforeWord && s[i] == ' ')
                return ans;
            else{
                spaceBeforeWord = true;
                ans++;
            }
        }

        return ans;
    }
};