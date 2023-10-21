//Bottom Up + Max Heap (Sliding Window)
//O(n*log(n))

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<int> dp(nums.size());
        for(int i=0;i<nums.size();i++)
            dp[i] = nums[i];
        
        priority_queue<pair<int, int>> max_heap;

        max_heap.push({dp[0], 0});
        for(int i=1;i<dp.size();i++){
            
            while(!max_heap.empty() && i-max_heap.top().second > k)
                max_heap.pop();
            
            dp[i] = max(dp[i] , nums[i] + max_heap.top().first);
            max_heap.push({dp[i], i});
        }

        return *max_element(begin(dp), end(dp));
    }
};