class Solution {
    public:
        long long coloredCells(int n) {
            long long ans = 0;
            for(int i=0; i<n; i++) {
                if(i == 0)
                    ans++;
                else
                    ans += (1LL * 4 * i);
            }
    
            return ans;
        }
    };