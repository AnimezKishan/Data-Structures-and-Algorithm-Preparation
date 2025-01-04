class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> letters;

        // 1. store all unique letters
        for(auto ch:s)
            letters.insert(ch);
        
        int ans = 0;
        // For each unique letter, repeat step 2 and 3
        for(auto letter : letters){

            int left_index = -1;
            int right_index = -1;

            // 2. find first and last occurance of letter
            for(int i=0;i<s.length();i++){
                if(s[i] == letter){
                    if(left_index == -1)
                        left_index = i;
                    
                    right_index = i;
                }
            }

            unordered_set<char> unique_mid;
            // 3. all unique characters in between of letter's first and last occurance, each contribute to forming a new palindromic subsequence of length 3.
            for(int k = left_index+1; k<right_index; k++)
                unique_mid.insert(s[k]);
                
            ans += unique_mid.size();
        }

        return ans;
    }
};