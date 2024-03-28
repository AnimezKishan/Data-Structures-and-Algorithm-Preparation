class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), i = 0, j = 0, ans = INT_MIN;
        unordered_map<int, int> m;

        while(j<n){

            m[nums[j]]++;

            while(m[nums[j]] > k){
                m[nums[i]]--;
                i++;
            }

            ans = max(ans, (j-i+1));
            j++;
        }

        return ans;
    }
};