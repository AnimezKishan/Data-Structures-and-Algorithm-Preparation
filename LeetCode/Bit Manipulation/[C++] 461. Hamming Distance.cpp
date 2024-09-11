class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        while(x || y) {
            int xEndBit = x & 1;
            int yEndBit = y & 1;

            // cout<<xEndBit<<" - "<<yEndBit<<endl;
            if(xEndBit ^ yEndBit == 1)
                ans++;
            
            x >>= 1;
            y >>= 1;
        }

        return ans;
    }
};