// Sieve of Eratosthenes

class Solution {
    public:
        vector<int> sieveHelper(int right) {
            vector<int> isPrime(right+1, true);
            isPrime[0] = false;
            isPrime[1] = false;
    
            for(int i=2; i*i <= right; i++) {
                if(isPrime[i] == true) {
                    for(int j=2; i*j <= right; j++)
                        isPrime[i*j] = false;
                }
            }
    
            return isPrime;
        }
        vector<int> closestPrimes(int left, int right) {
            vector<int> isPrime = sieveHelper(right);
    
            vector<int> primes;
            for(int i=left; i<=right; i++)
                if(isPrime[i] == true)
                    primes.push_back(i);
    
            vector<int> ans = {-1, -1};
            int minDiff = INT_MAX;
            for(int i=1; i<primes.size(); i++) {
                int diff = primes[i] - primes[i-1];
    
                if(diff < minDiff) {
                    minDiff = diff;
                    ans = { primes[i-1], primes[i] };
                }
            }
    
            return ans;
        }
    };