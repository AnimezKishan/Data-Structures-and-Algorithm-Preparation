// The goal of this problem is to convert base10 system to base26 system

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while(columnNumber > 0)
        {
            //addition of character at starting of string.
            ans = char('A' + (columnNumber - 1) % 26) + ans;
            columnNumber = (columnNumber-1)/26;  
        }
        return ans;
    }
};