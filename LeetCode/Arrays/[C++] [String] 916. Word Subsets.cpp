// TC -> O(M+N)
// SC -> O(1)
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> max_freq(26, 0);
        // 1. You need to iterate through all words in words2 and find out what is the maximum frequency of each alphabet. Like, a might appear mostly 3 times in some word of word2, so make a map / vector for that, call it max_freq.
        for(string &s : words2) {
            vector<int>currWordFreq(26, 0);
            for(char &ch : s)
                currWordFreq[ch - 'a']++;
            
            for(int i=0; i<26; i++)
                max_freq[i] = max(max_freq[i], currWordFreq[i]);
        }

        
        // 2. Now, iterate through every word in words1, and make its own char-frequency map. Then compare , if this word have lesser frequency for any character than stored in max_freq, this word is not universal.
        vector<string> ans;
        for(string &s : words1) {
            vector<int>currWordFreq(26, 0);
            for(char &ch : s)
                currWordFreq[ch - 'a']++;

            int i;
            for(i=0; i<26; i++)
                if(currWordFreq[i] < max_freq[i])
                    break;
            if(i == 26)
                ans.push_back(s);
        }

        return ans;
    }
};