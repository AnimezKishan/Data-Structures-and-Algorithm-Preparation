//each character can only be used once --> each character from 'chars' can only be used once for a particular string. 

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> map(26, 0);

        for(int i=0;i<chars.length();i++)
            map[chars[i]-'a']++;

        int ans = 0;
        for(int i=0;i<words.size();i++){
            vector<int> temp(26, 0);
            int j = 0;
            for(;j<words[i].length();j++){
                int ch = words[i][j] - 'a';
                if(map[ch] > 0 && temp[ch] < map[ch]){
                    temp[ch]++;
                }
                else{
                    break;
                }
            }
            if(j == words[i].length())
                ans += j;
        }

        return ans;
        
    }
};