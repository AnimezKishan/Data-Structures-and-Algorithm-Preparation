class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        while(start || goal) {
            int startEndBit = start & 1;
            int goalEndBit = goal & 1;

            // cout<<startEndBit<<" - "<<goalEndBit<<endl;
            if(startEndBit ^ goalEndBit == 1)
                ans++;
            
            start >>= 1;
            goal >>= 1;
        }

        return ans;
    }
};