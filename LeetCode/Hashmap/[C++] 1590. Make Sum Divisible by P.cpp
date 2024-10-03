// Cummulative Sum + Hashmap

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        /*
        long long sum = 0;
        for(int &num : nums)
            sum += num;
        
        int target = sum % p;
        */

        //Effectively doing the same above computation
        int totalSum = 0;
        for (int &num : nums)
            totalSum = (totalSum + num) % p;

        // If total sum is already divisible by p, no need to remove anything
        if (totalSum == 0) return 0;

        int target = totalSum; 
        unordered_map<int, int> prefixModMap;
        prefixModMap[0] = -1; // base case for prefix sum at the start
        
        int prefixSum = 0;
        int ans = n;
        
        for (int i = 0; i < n; i++) {
            prefixSum = (prefixSum + nums[i]) % p;

            int requiredRemainder = (prefixSum - target + p) % p;

            // If we have seen the required remainder before
            if (prefixModMap.find(requiredRemainder) != prefixModMap.end()) {
                int subarrayLength = i - prefixModMap[requiredRemainder];
                ans = min(ans, subarrayLength);
            }

            // Store the current prefix sum's modulo
            prefixModMap[prefixSum] = i;
        }

        // If no subarray was found that fulfills the condition, return -1
        return ans == n ? -1 : ans;
    }
};
