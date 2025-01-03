// Prefix Sum

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();

        // prefixSum from right to left
        vector<long long int> prefixSum(n, 0);
        prefixSum[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--) 
            prefixSum[i] = nums[i] + prefixSum[i+1];
        
        int ans = 0;
        long long int sum = 0;
        for(int i=0; i<n-1; i++) {
            sum += nums[i];
            if(sum >= prefixSum[i+1])
                ans++;
        }

        return ans;
    }
};