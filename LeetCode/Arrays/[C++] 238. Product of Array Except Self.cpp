/*
prefix and suffix do there jo simulatiously.
e.x. nums = [1, 2, 3, 4] 
ans = [1, 1, 1, 1]

1st Iteration -> [1, 1, 1, 1], prefix = 1, suffix = 4
2nd Iteration -> [1, 1, 4, 1], prefix = 2, suffix = 12
3rd Iteration -> [1, 12, 8, 1], prefix = 6, suffix = 24
4th Iteration -> [24, 12, 8, 6], prefix = 24, suffix = 24
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        int prefix = 1, suffix = 1;

        for(int i=0;i<n;i++){
            ans[i] *= prefix;
            prefix *= nums[i];

            ans[n-1-i] *= suffix;
            suffix *= nums[n-1-i];
        }

        return ans;

    }
};