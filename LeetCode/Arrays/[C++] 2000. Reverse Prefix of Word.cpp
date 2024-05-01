// Two Pointer

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.length();
        int i = 0, j;
        while(i<n){
            if(word[i] == ch){
                j = i;
                break;
            }
            i++;
        }

        if(i == n)
            return word;
        else{
            i = 0;
            while(i<j)
                swap(word[i++], word[j--]);
        }

        return word;
    }
};