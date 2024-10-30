// Bottom-Up

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        // calculate Longest Increasing and Decreasing Subsequenece for each index.
        vector<int> LIS(n, 1);
        vector<int> LDS(n, 1);

        // calculate LIS
        for(int i=0; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(nums[i] > nums[j])
                    LIS[i] = max(LIS[i], LIS[j]+1);
            }
        }

        // calculate LDS
        for(int i=n-1; i>=0; i--) {
            for(int j = i+1; j<n; j++){
                if(nums[i] > nums[j])
                    LDS[i] = max(LDS[i], LDS[j]+1);
            }
        }

        // using LIS and LDS for each element, calculate no. of elements need to be removed.
        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            // arr length should be >= 3
            if(LIS[i] > 1 && LDS[i] > 1){
                int leftRemoval = (i+1) - LIS[i];
                int rightRemoval = (n-i) - LDS[i];

                ans = min(ans, leftRemoval + rightRemoval);
            }
        }

        return ans;
    }
};