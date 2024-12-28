class Solution {
public:
    int dp[20001][4];
    int helper(vector<int> &subArraySum, int idx, int arrCnt, int k) {
        if(arrCnt == 0)
            return 0;
        
        if(idx >= subArraySum.size()) // invalid case - no. of subarrays needed i.e. 3 not fulfilled
            return INT_MIN;

        if(dp[idx][arrCnt] != -1)
            return dp[idx][arrCnt];
        
        int take = subArraySum[idx] + helper(subArraySum, idx+k, arrCnt-1, k);
        int not_take = helper(subArraySum, idx+1, arrCnt, k);

        return dp[idx][arrCnt] = max(take, not_take);
    }
    void solve(int idx, int arrCnt, int k, vector<int> &ans, vector<int> &subArraySum) {
        if(arrCnt == 0 || idx >= subArraySum.size())
            return;

        int take = subArraySum[idx] + helper(subArraySum, idx+k, arrCnt-1, k);
        int not_take = helper(subArraySum, idx+1, arrCnt, k);

        if(take >= not_take) {
            ans.push_back(idx);
            solve(idx+k, arrCnt-1, k, ans, subArraySum);
        } else {
            solve(idx+1, arrCnt, k, ans, subArraySum);
        }
        
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> subArraySum;
        int i = 0, j = 0;
        int windowSum = 0;
        while(j < nums.size()) {
            windowSum += nums[j];
            while(j-i+1 == k) {
                subArraySum.push_back(windowSum);
                windowSum -= nums[i];
                i++;
            }

            j++;
        }

        vector<int> ans;
        memset(dp, -1, sizeof(dp));
        solve(0, 3, k, ans, subArraySum);

        return ans;
    }
};