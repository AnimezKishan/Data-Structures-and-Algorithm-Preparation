/*
https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/comments/1570312

Concatenating two long strings and then comparing them.
What if there are huge number of words in each array? You may run out of memory.
What if the first characters of the first word in arrays are different? You wasted too much time on concatenating.

Assuming following engineering case, you are receiving data frames endlessly from a source on two seperated communicating channels at 1Mbps. Each data frame contains 1 to 16 bytes of data, so receiving a frame may take 8 - 96 us (longer in real life, because of overheads) . The data bytes on two channels should be exactly same (contents, and order). But the frame size may differ. Now you are required to reset communicationg hardware within 200 us if a data mismatch on two channels is detected.
Can you create two memory areas, fill them up with received data till the source stop transmitting, so you can concatenate them and run comparison later? Absolutely no!
*/

//Two Pointer
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, j =0; // string traverse
        int m = 0, n = 0; // char traverse

        while(i<word1.size() && j<word2.size()){
            
            if(word1[i][m++] != word2[j][n++])
                return false;
            
            if(m >= word1[i].length()){
                i++;
                m = 0;
            }

            if(n >= word2[j].length()){
                j++;
                n = 0;
            }
        }

        return ((i == word1.size()) && (j == word2.size()));
    }
};


// Concatenating
/*
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1, s2;
        for(auto i:word1)
            s1 += i;
        
        for(auto i:word2)
            s2 += i;
        
        return (s1 == s2);

    }
};
*/