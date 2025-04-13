class Solution {
    public:
        int MOD = 1e9 + 7;
        int findPow(long long a, long long b) {
            if(b == 0)
                return 1;
            
            long long half = findPow(a, b/2);
            long long ans = (half * half) % MOD;
    
            if(b % 2 == 1)
                ans = (ans * a) % MOD;
            
            return ans;
        }
        int countGoodNumbers(long long n) {
            long long evenIdxs = (n+1)/2;
            long long oddIdxs = n/2;
    
            // Even options - 0,2,4,6,8 - count = 5
            // prime options - 2,3,5,7 - count = 4
            return (long long)findPow(5, evenIdxs) * findPow(4, oddIdxs) % MOD; 
        }
    };