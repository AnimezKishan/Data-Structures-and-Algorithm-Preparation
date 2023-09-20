class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        unordered_map<int, int> m;
        m[0] = -1;

        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            m[sum] = i;
        }

        if(sum < x)
            return -1;
        
        int remainingSum = sum - x;
        int longestSubArray = INT_MIN;

        sum = 0;
        for(int i=0;i<n;i++)
        {
            sum += nums[i];

            int findSum = sum - remainingSum;

            if(m.find(findSum) != m.end())
            {
                int idx = m[findSum];

                longestSubArray = max(longestSubArray, i-idx);

            }
        }
        return (longestSubArray == INT_MIN ? -1 : n-longestSubArray);
    }
};