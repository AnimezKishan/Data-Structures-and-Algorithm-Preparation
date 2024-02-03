class Solution {
public:
    int dp[501];
    int solve(int i, vector<int> &arr, int k){
        if(i >= arr.size())
            return 0;

        if(dp[i] != -1)
            return dp[i];
        
        int result = 0;
        int currSum = -1;

        for(int j=i;j<arr.size() && j-i+1<=k;j++){
            currSum = max(currSum, arr[j]);
            result = max(result, ((j-i+1) * currSum) + solve(j+1, arr, k));
        }

        return dp[i] = result;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(0, arr, k);
    }
};