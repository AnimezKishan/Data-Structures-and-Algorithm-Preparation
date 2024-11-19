class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int distinctCount = 0;
        unordered_map<int, int> mp;

        long long prefixSum = 0, ans = 0;
        for(int i=0; i<k; i++) {
            mp[nums[i]]++;
            prefixSum += nums[i];

            if(mp[nums[i]] == 1)
                distinctCount++;
        } 

        if(distinctCount == k)
            ans = max(ans, prefixSum);

        int i = 0, j = k;
        while(j < nums.size()) {
            mp[nums[j]]++;
            prefixSum += nums[j];
            if(mp[nums[j]] == 1)
                distinctCount++;
            j++;

            mp[nums[i]]--;
            prefixSum -= nums[i];
            if(mp[nums[i]] == 0)
                distinctCount--;
            i++;

            if(distinctCount == k)
                ans = max(ans, prefixSum);
        }

        return ans;
    }
};