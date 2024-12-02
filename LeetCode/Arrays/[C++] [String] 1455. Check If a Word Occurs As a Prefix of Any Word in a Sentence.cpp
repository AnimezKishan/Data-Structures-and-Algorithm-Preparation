class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int wordCount = 0;
        for(int i=0; i<sentence.length(); i++) {
            int j = 0;
            while(j<searchWord.length() && searchWord[j] == sentence[i]) {
                j++;
                i++;
            }
            wordCount++;
            if(j == searchWord.length())
                return wordCount;
            else {
                while(i<sentence.length() && sentence[i] != ' ')
                    i++;
            }
        }

        return -1;
    }
};