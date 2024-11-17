class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        int j = 0, ans = INT_MAX;
        vector<long long> cumSum(n, 0);
        deque<int> dq; // to store the index in increasing order of cummulative sum

        while(j < n) {
            if(j == 0)
                cumSum[j] = nums[j]; 
            else
                cumSum[j] = cumSum[j-1] + nums[j];

            if(cumSum[j] >= k)
                ans = min(ans, j+1);
            
            // to shrink the window if possible
            while(!dq.empty() && cumSum[j] - cumSum[dq.front()] >= k) {
                ans = min(ans, j - dq.front());
                dq.pop_front();
            }

            // keeping the monotonic deque in increasing order
            while(!dq.empty() && cumSum[j] <= cumSum[dq.back()])
                dq.pop_back();
            
            dq.push_back(j);
            j++;
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};