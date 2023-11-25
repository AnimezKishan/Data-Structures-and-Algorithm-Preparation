class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n, nums[0]);
        for(int i=1;i<n;i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(i == 0)
                ans.push_back(prefixSum[n-1] - (nums[i] * nums.size()));
            else{
                int left = (i*nums[i]) - prefixSum[i-1];
                int right = (prefixSum[n-1] - prefixSum[i]) - (nums[i] * (n-i-1));
                ans.push_back(left + right);
            }
        }

        return ans;
    }
};