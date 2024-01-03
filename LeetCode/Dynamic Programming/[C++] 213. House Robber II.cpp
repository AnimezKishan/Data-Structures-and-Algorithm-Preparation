/*
Here, first and last elements are neighbour so,
you have to take MAX out from two cases:
    -> don't consider the first house, so last house don't get it as neighbour
    -> don't consider the last house, so first house don't get it as neighbour
*/

class Solution {
public:
    int dp[101];
    int solve(int i, vector<int> &nums){
        if(i == 0)
            return nums[0];
        
        if(i < 0)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int take = 0, leave = 0;
        take = nums[i] + solve(i-2, nums);
        leave = solve(i-1, nums);

        return dp[i] = max(take, leave);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        vector<int> considerLast(begin(nums) + 1, end(nums)), considerFirst(begin(nums), end(nums) - 1);
        memset(dp, -1, sizeof(dp));
        int way1 = solve(considerLast.size()-1, considerLast);
        memset(dp, -1, sizeof(dp));
        int way2 = solve(considerFirst.size()-1, considerFirst);
        return max(way1, way2);
    }
};