class Solution {
public:
    int m, n;
    int t[501][501];
    
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j, vector<vector<int>> &dp) {
        if(i == m || j == n)
            return -100000000; //send a large negative number. Don't send 0 because we can have -ve product as well. For example : {-1, -1}, {1, 1}, output should be -1.
        
        if(dp[i][j] != -1e9)
            return dp[i][j];
        
        int val = nums1[i] * nums2[j];
        
        int take_i_j = solve(nums1, nums2, i+1, j+1, dp) + val;
        
        int take_i = solve(nums1, nums2, i, j+1, dp);
        int take_j = solve(nums1, nums2, i+1, j, dp);
        
        
        return dp[i][j] = max({val, take_i_j, take_i, take_j});
        
        
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();
        vector<vector<int>> dp(501, vector<int>(501, -1e9));
        return solve(nums1, nums2, 0, 0, dp);
    }
};