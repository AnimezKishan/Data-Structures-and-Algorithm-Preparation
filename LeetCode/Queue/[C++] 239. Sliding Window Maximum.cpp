class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        for(int i=0;i<nums.size();i++)
        {
            //sliding window
            while(!dq.empty() && i-dq.front() >= k)
                dq.pop_front();
            
            //previous greater element algo
            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);

            //storing in ans
            if(i >= k-1)
                ans.push_back(nums[dq.front()]);
            
        }
        return ans;
    }
};