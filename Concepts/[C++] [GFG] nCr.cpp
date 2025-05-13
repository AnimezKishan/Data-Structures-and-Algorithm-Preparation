// Binomial Coefficient, nCr using Binary Exponentiation & Fermat's Little Theorem
class Solution {
  public:
    int M = 1e9 + 7;
    // Binary Exponentiation
    int findPower(long long a, long long b) {
        if(b == 0)
            return 1;
        
        long long half = findPower(a, b/2);
        long long result = (half * half) % M;
        
        if(b % 2 != 0)
            result = (result * a) % M;
            
        return result;
    }
    int nCr(int n, int r) {
        // nCr = n!/r! * (n-r)!
        if(r > n) return 0;
        vector<long long> fact(n+1, 1);
        for(int i=2; i<=n; i++) {
            fact[i] = (i * fact[i-1]) % M;
        }
        
        long long A = fact[n];
        long long B = (fact[r] * fact[n-r]) % M;
        
        // fermat's little theorem, B^-1 % M = pow(B, M-2) % M
        long long invB = findPower(B, M-2) % M;
        
        return ((A * invB) % M);
    }
};