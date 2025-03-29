// Primes using Seive, BinaryExponentiation, NextGreater, PrevGreater, Sorting
//T.C : O(mloglogm + nlogm + nlogn + nlogk)
//S.C : O(m+n), where m = maxElement, n = nums.size()
class Solution {
    public:
        const int MOD = 1e9 + 7;
        
        long long findPower(long long a, long long b) {
            if (b == 0) return 1;
            long long half = findPower(a, b / 2);
            long long result = (half * half) % MOD;
            if (b % 2 == 1) {
                result = (result * a) % MOD;
            }
            return result;
        }
    
        vector<int> getPrimes(int limit) {
            vector<bool> isPrime(limit + 1, true);
            vector<int> primes;
    
            for (int i = 2; i * i <= limit; i++) {
                if (isPrime[i]) {
                    for (int j = i * i; j <= limit; j += i) {
                        isPrime[j] = false;
                    }
                }
            }
    
            for (int i = 2; i <= limit; i++) {
                if (isPrime[i]) {
                    primes.push_back(i);
                }
            }
    
            return primes;
        }
    
        vector<int> findPrimeScores(vector<int>& nums) {
            int n = nums.size();
            vector<int> primeScores(n, 0);
    
            int maxElement = *max_element(begin(nums), end(nums));
            vector<int> primes = getPrimes(maxElement); //O(mloglogm)
    
            for(int i = 0; i < n; i++) { //O(n * log(m))
                int num = nums[i];
    
                for(int prime : primes) {
                    if(prime*prime > num) {
                        break;
                    }
    
                    if(num % prime != 0) {
                        continue;
                    }
    
                    primeScores[i]++;
                    while(num%prime == 0) {
                        num /= prime;
                    }
                }
                if(num > 1) { //example : 15 : 3, 5
                    primeScores[i]++;
                }
            }
    
            return primeScores;
        }
    
        vector<int> findNextGreater(vector<int>& primeScores) {
            int n = primeScores.size();
            vector<int> nextGreator(n, n);
            stack<int> st;
    
            for(int i = n-1; i >= 0; i--) {
                while(!st.empty() && primeScores[st.top()] <= primeScores[i]) {
                    st.pop();
                }
    
                nextGreator[i] = st.empty() ? n : st.top();
                st.push(i);
            }
    
            return nextGreator;
        }
    
        vector<int> findPrevGreater(vector<int>& primeScores) {
            int n = primeScores.size();
            vector<int> prevGreator(n, -1);
            stack<int> st;
    
            for(int i = 0; i < n; i++) {
                while(!st.empty() && primeScores[st.top()] < primeScores[i]) {
                    st.pop();
                }
    
                prevGreator[i] = st.empty() ? -1 : st.top();
                st.push(i);
            }
    
            return prevGreator;
        }
    
        int maximumScore(vector<int>& nums, int k) {
            vector<int> primeScores = findPrimeScores(nums); //O(mloglogm + n*log(m))
            vector<int> nextGreater = findNextGreater(primeScores); //O(n)
            vector<int> prevGreater = findPrevGreater(primeScores); //O(n)
    
            int n = nums.size();
            vector<long long> subarrays(n, 0);
    
            for(int i = 0; i < n; i++) { //O(n)
                subarrays[i] = (long long)(nextGreater[i] - i) * (i - prevGreater[i]);
            }
    
            vector<pair<int, int>> sortedNums(n);
            for(int i = 0; i < n; i++) {
                sortedNums[i] = {nums[i], i};
            }
    
            sort(begin(sortedNums), end(sortedNums), greater<>()); //O(nlogn)
    
            long long score = 1;
    
            int idx = 0; //start from largest element greedily
            while(k > 0) { //O(k * log(operations))
                auto [num, i] = sortedNums[idx];
    
                long long operations = min((long long)k, subarrays[i]);
    
                score = (score * findPower(num, operations)) % MOD;
    
                k  = (k - operations);
                idx++;
            }
    
            return score;
            
        }
    };