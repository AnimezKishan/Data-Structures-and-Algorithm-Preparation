class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxIncreasing = 1, maxDecreasing = 1;
        int currIncreasing = 1, currDecreasing = 1;

        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i] < nums[i+1]){
                currIncreasing++;
                maxIncreasing = max(maxIncreasing, currIncreasing);
            }
            else
                currIncreasing = 1;
            
            if(nums[i] > nums[i+1]) {
                currDecreasing++;
                maxDecreasing = max(maxDecreasing, currDecreasing);
            }
            else
                currDecreasing = 1;
        }

        return max(maxIncreasing, maxDecreasing);

    }
};