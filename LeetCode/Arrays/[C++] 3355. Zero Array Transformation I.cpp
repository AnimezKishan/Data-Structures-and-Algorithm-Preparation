// Difference Array

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diffArray(n, 0);
        for(vector<int> &query : queries) {
            int l = query[0];
            int r = query[1];

            diffArray[l]++;
            if(r+1 < n)
                diffArray[r+1]--;
        }

        int prev = 0;
        for(int i=0; i<n; i++) {
            diffArray[i] += prev;
            prev = diffArray[i];

            if(diffArray[i] < nums[i])
                return false;
        }

        return true;
    }
};