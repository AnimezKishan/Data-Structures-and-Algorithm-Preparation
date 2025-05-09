class Solution {
public:
    int n, totalDigitSum;
    long long totalPermPossible;
    int M = 1e9 + 7;

    int findPower(long long a, long long b) {
        if(b == 0)
            return 1;
        
        long long half = findPower(a, b/2);
        long long result = (half * half) % M;
        if(b % 2 == 1) {
            result = (result * a) % M;
        }

        return result;
    }

    int solve(int digit, int evenIndexDigitCount, int currSum, vector<int> &freq, vector<long long> &fermatFact, vector<vector<vector<int>>> &dp) {
        if(digit == 10) {
            if(currSum == totalDigitSum/2 && evenIndexDigitCount == ((n+1)/2))
                return totalPermPossible;
            
            return 0;
        }

        if(dp[digit][evenIndexDigitCount][currSum] != -1)
            return dp[digit][evenIndexDigitCount][currSum];

        long long ways = 0;

        for(int count=0; count<=min(freq[digit], (n+1)/2 - evenIndexDigitCount); count++) {
            int evenPosCount = count;
            int oddPosCount = freq[digit] - count;

            long long div = (fermatFact[evenPosCount] * fermatFact[oddPosCount]) % M;

            long long val = solve(digit + 1, evenIndexDigitCount + evenPosCount, currSum + digit*count, freq, fermatFact, dp);

            ways = (ways + (val * div) % M) % M;

        }
        return dp[digit][evenIndexDigitCount][currSum] = ways;
    }

    int countBalancedPermutations(string num) {
        n = num.length();
        totalDigitSum = 0;

        vector<int> freq(10, 0);
        for(int i=0; i<n; i++) {
            totalDigitSum += num[i] - '0';
            freq[num[i] - '0']++;
        }

        if(totalDigitSum % 2 != 0)
            return 0;

        // Precomputing Factorial
        vector<long long> fact(n+1, 1);
        for(int i=2; i<=n; i++) {
            fact[i] = (fact[i-1] * i) % M;
        }

        // Precomputing FermatFactorial --> (1/x)%M 
        vector<long long> fermatFact(n+1, 1);
        for(int i=0; i<=n; i++) {
            fermatFact[i] = findPower(fact[i], M-2) % M;
        }

        totalPermPossible = (1LL * fact[(n+1)/2] * fact[n/2]) % M; // No. of even indices(n+1/2) and no. of odd indices(n/2)

        vector<vector<vector<int>>> dp(10, vector<vector<int>>(((n+1)/2+1), vector<int>(totalDigitSum+1, -1)));
        return solve(0, 0, 0, freq, fermatFact, dp);
    } 
};