class Solution {
public:
    string largestOddNumber(string num) {
        for(int j=num.length();j>=0;j--)
          if((num[j] - '0')&1)
            return num.substr(0, j+1);
        
        return "";
    }
};