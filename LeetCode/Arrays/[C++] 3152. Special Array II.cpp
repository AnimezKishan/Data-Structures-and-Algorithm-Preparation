// Prefix Sum

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        // store the count of voilating indices
        int n = nums.size();
        vector<int> cumSum(n);
        cumSum[0] = 0;
        for(int i=1; i<n; i++) {
            // if both adjacents are even or odd
            if((nums[i]&1 && nums[i-1]&1) || (!(nums[i]&1)) && !(nums[i-1]&1))
                cumSum[i] = cumSum[i-1] + 1;
            else
                cumSum[i] = cumSum[i-1];
        }

        vector<bool> ans;
        for(vector<int> &query : queries) {
            int start = query[0];
            int end = query[1];

            ans.push_back(cumSum[end] - cumSum[start] == 0);
        }

        return ans;
    }
};