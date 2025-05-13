class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int M = 1e9 + 7;
        vector<int> mp(26, 0);
        for(char &ch : s) 
            mp[ch-'a']++;
        
        while(t) {
            vector<int> temp(26, 0);
            for(int i=0; i<26; i++) {
                char ch = i + 'a';
                int freq = mp[i];

                if(ch == 'z') {
                    temp[0] = (temp[0] + freq) % M;
                    temp[1] = (temp[1] + freq) % M;
                } else {
                    temp[(ch+1) - 'a'] = (temp[(ch+1) - 'a'] + freq) % M;
                }
            }

            mp = move(temp);
            t--;
        }

        int ans = 0;
        for(int i=0; i<26; i++)
            ans = (ans + mp[i]) % M;
        
        return ans;
    }
};