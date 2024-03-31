class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minKPosition = -1, maxKPosition = -1, culpritPosition = -1, temp;
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] < minK || nums[i] > maxK){
                culpritPosition = i;
            }
            else{
                if(nums[i] == minK)
                    minKPosition = i;
                if(nums[i] == maxK)
                    maxKPosition = i;
            }

            temp = min(minKPosition, maxKPosition) - culpritPosition;
            ans += (temp < 0) ? 0 : temp;
        }

        return ans;
    }
};