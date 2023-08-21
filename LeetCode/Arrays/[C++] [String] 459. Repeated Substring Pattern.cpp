/*
-> Create a string double of it's length with itself repeating.
-> If string has repeating substring
    -> it would get found on the index which will be less than ending index of string.
-> If not, 
    -> it gets found out in the second iteration of string, as string got doubled in size.
*/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s+s).find(s, 1) < s.size();
    }
};