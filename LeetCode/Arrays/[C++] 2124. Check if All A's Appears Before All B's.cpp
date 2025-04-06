class Solution {
    public:
        bool checkString(string s) {
            int lastPosA = -1, firstPosB = 101;
            for(int i=0; i<s.length(); i++) {
                if(s[i] == 'a')
                    lastPosA = i;
                else if(s[i] =='b' && firstPosB == 101)
                    firstPosB = i; 
            }
    
            return lastPosA < firstPosB;
        }
    };