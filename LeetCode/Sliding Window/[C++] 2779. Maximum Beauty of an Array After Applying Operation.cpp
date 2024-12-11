class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // The problem becomes the following: find maximum subarray A[i … j] such that A[j] - A[i] ≤ 2 * k.
        int i = 0, j = 0, ans = 0;
        while(j<n) {
            while(nums[j] - nums[i] > 2*k)
                i++;
            
            ans = max(ans, j-i+1);
            j++;
        }

        return ans;
    }
};