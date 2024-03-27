class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        // Edge Case, you can't find any product that is less than 1.
        if(k <= 1)
            return 0;
        
        int n = nums.size();
        int i = 0, j = 0, count = 0, tempProd = 1;

        while(j<n){
            tempProd *= nums[j];

            while(tempProd >= k){
                tempProd /= nums[i];
                i++;
            }

            // j-i+1 = no. of subarrays between i and j
            count += (j-i+1);
            j++;
        }

        return count;
    }
};