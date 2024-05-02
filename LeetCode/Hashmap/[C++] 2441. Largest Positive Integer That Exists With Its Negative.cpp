class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int, bool> m;
        int ans = -1;

        for(int i=0;i<nums.size();i++)
            if(nums[i] > 0)
                m[nums[i]] = 1;

        for(int i=0;i<nums.size();i++){
            if(nums[i] < 0 && m[abs(nums[i])] && abs(nums[i]) > ans)
                ans = abs(nums[i]);
        }

        return ans;
    }
};