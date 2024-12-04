class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int j = 0;
        for(int i=0; i<str1.length(); i++) {
            if(j == str2.length())
                return true;

            int char1 = str1[i] - 'a';
            int char2 = str2[j] - 'a';

            if(char1 == char2 || char2 == ((char1 + 1) % 26))
                j++;
        }

        return j == str2.length() ? true : false;
    }
};