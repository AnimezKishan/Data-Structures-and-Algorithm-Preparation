class Solution {
    public:
        vector<vector<int>> dp;
    
        bool dfs(int i, int target, vector<int>& nums) {
            if (target == 0) return true;
            if (i == nums.size() || target < 0) return false;
    
            if (dp[i][target] != -1) return dp[i][target];
    
            // Choose or not choose the current number
            bool include = dfs(i + 1, target - nums[i], nums);
            bool exclude = dfs(i + 1, target, nums);
    
            return dp[i][target] = include || exclude;
        }
    
        bool canPartition(vector<int>& nums) {
            int totalSum = accumulate(nums.begin(), nums.end(), 0);
            // If the total sum of the array is odd, then dividing it into two equal subsets is impossible. Return false immediately in such cases.
            if (totalSum % 2 != 0) return false;
    
            /*
            Set your goal as targetSum = sum / 2. Now the task becomes: "Can I form a subset of nums that sums to targetSum?"
            Because if you find a subset with the sum upto targetSum then the remaining elements of the array with accumulate the other half of targetSum.
            */
            int target = totalSum / 2;
            dp.resize(nums.size(), vector<int>(target + 1, -1));
            return dfs(0, target, nums);
        }
    };
    