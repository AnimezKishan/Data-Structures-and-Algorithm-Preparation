class Solution {
    public:
        int secondHighest(string s) {
            int maxElem = -1, secondMax = -1;
            for(int i=0; i<s.length(); i++) {
                if(isdigit(s[i])) {
                    int digit = s[i] - '0';
                    if(digit > maxElem) {
                        secondMax = maxElem;
                        maxElem = digit;
                    } else if (digit != maxElem && digit > secondMax) {
                        secondMax = digit;
                    }
                }
            }
    
            return maxElem == secondMax ? -1 : secondMax;
        }
    };