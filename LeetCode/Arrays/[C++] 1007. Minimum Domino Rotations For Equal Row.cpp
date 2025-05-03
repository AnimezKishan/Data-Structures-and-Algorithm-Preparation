// Approach I
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        for(int i=1; i<=6; i++) {
            int swapCount = 0, sameCount = 0;
            bool isPoss = true;
            for(int j=0; j<n; j++) {
                if(tops[j] == i && bottoms[j] == i)
                    sameCount++;
                else if(tops[j] == i)
                    continue;
                else if(bottoms[j] == i) 
                    swapCount++;
                else {
                    isPoss = false;
                    break;
                }
            }

            if(isPoss) {
                return min(swapCount, n-sameCount-swapCount);
            }
        }

        return -1;
    }
};


// Approach II
class Solution {
public:
    int minDominoRotations(vector<int>& t, vector<int>& b) {
        vector<int> countT(7), countB(7), same(7);
        int n = t.size();
        for(int i=0;i<n;i++)
        {
            countT[t[i]]++;
            countB[b[i]]++;
            if(t[i] == b[i])
                same[t[i]]++;
        }
        for(int i=1;i<7;i++)
        {
            if(countT[i] + countB[i] - same[i] == n)
                return n-max(countT[i], countB[i]);
        }
        return -1;
    }
};