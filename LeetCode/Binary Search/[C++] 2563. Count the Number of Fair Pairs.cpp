/*
if we have x pairs such that nums[i] + nums[j] < lower and
y pairs such that nums[i] + nums[j] <= upper

Therefore, y - x => no. of pairs such that lower <= nums[i] + nums[j] <= upper 

Also, If nums[i] + k < lower, so k i.e. lower - nums[i] is the number which when added with nums[i] < lower
So, nums[i] + k/no. less that k  < lower.
Similar for nums[i] + k <= upper 
*/
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        // as we need nums[i] + nums[j], so i < j doesn't matter that much.
        sort(nums.begin(), nums.end());

        long long ans = 0;
        for(int i=0; i<n; i++) {
            // This will help us find no. of elements after nums[i] whose sum with nums[i] < lower
            int idx = lower_bound(begin(nums) + i + 1, end(nums), lower - nums[i]) - begin(nums); // gives index of first element not less than lower - nums[i]
            int x = idx - i - 1; // No. of pairs whose sum is < lower

            // This will help us find no. of elements after nums[i] whose sum with nums[i] <= upper
            idx = upper_bound(begin(nums) + i + 1, end(nums), upper - nums[i]) - begin(nums); // gives index of first element greater than upper - nums[i]
            int y = idx - i - 1; // No. of pairs whose sum is <= upper

            ans += y-x;
        }

        return ans;
    }
};