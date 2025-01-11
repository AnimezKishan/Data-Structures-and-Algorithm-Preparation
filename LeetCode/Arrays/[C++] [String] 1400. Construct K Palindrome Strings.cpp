class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        if(n < k)
            return false;
        
        vector<int> charCount(26, 0);
        for(char &ch : s)
            charCount[ch - 'a']++;
        
        int oddFreq = 0;
        for(int i=0; i<26; i++)
            if(charCount[i] & 1)
                oddFreq++;
        
        if(oddFreq > k)
            return false;
        else
            return true;
    }
};