class Solution {
public:
    int minimumLength(string s) {
        vector<int> charCount(26, 0);

        for(char &ch : s)
            charCount[ch-'a']++;
        
        int ans = 0;
        for(int i=0; i<26; i++)
            if(charCount[i] & 1)
                ans += 1;
            else if(charCount[i] > 0)
                ans += 2;

        return ans;
    }
};