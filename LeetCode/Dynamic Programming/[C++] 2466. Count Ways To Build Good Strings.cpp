class Solution {
public:
    vector<int> dp;
    const int MOD = 1e9 + 7;
    int solve(int len, int &low, int &high, int &zeroCount, int &oneCount) {
        bool addOne = false;
        if(len >= low && len <= high)
            addOne = true;
        
        if(len > high)
            return 0;

        if(dp[len] != -1)
            return dp[len];

        int takeZero = solve(len+zeroCount, low, high, zeroCount, oneCount);
        int takeOne = solve(len+oneCount, low, high, zeroCount, oneCount);

        return dp[len] = (addOne + takeZero + takeOne) % MOD;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        dp.resize(high+1, -1);
        return solve(0, low, high, zero, one);
    }
};