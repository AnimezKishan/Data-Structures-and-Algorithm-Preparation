class Solution {
    public:
        string pushDominoes(string dominoes) {
            int n = dominoes.length();
            vector<int> leftToRight(n);
            leftToRight[0] = dominoes[0] == 'R' ? 0 : -1;
    
            for(int i=1; i<n; i++) {
                if(dominoes[i] == 'L')
                    leftToRight[i] = -1;
                else if(dominoes[i] == 'R')
                    leftToRight[i] = i;
                else if(leftToRight[i-1] != -1)
                    leftToRight[i] = leftToRight[i-1];
                else
                    leftToRight[i] = -1;
            }
    
            vector<int> rightToLeft(n);
            rightToLeft[n-1] = dominoes[n-1] == 'L' ? n-1 : -1;
    
            for(int i=n-2; i>=0; i--) {
                if(dominoes[i] == 'R')
                    rightToLeft[i] = -1;
                else if(dominoes[i] == 'L')
                    rightToLeft[i] = i;
                else if(rightToLeft[i+1] != -1)
                    rightToLeft[i] = rightToLeft[i+1];
                else 
                    rightToLeft[i] = -1;
            }
    
            string ans = "";
            for(int i=0; i<n; i++) {
                int prevRightDistance = abs(i - leftToRight[i]);
                int nextLeftDistance = abs(i - rightToLeft[i]);
    
                if(leftToRight[i] == rightToLeft[i])
                    ans += ".";
                else if(leftToRight[i] == -1)
                    ans += "L";
                else if(rightToLeft[i] == -1)
                    ans += "R";
                else if(prevRightDistance == nextLeftDistance)
                    ans += ".";
                else
                    ans += prevRightDistance < nextLeftDistance ? "R" : "L";
            }
    
            return ans;
        }
    };