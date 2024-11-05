class Solution {
public:
    int minChanges(string s) {
        char currCh = s[0];
        int consecutiveCount = 0;
        int minChanges = 0;

        for(int i=0; i<s.length(); i++) {
            if(s[i] == currCh){
                consecutiveCount++;
                continue;
            }

            if(consecutiveCount % 2 == 0){
                consecutiveCount = 1;
            }
            else{ // if count is odd, flip the last bit
                consecutiveCount = 0;
                minChanges++;
            }

            currCh = s[i];
        }

        return minChanges;
    }
};