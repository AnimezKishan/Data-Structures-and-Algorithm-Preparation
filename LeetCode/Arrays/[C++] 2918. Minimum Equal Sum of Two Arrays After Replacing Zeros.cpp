class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int firstZeroCount = 0, secondZeroCount = 0;
        long long firstSum = 0, secondSum = 0;
        for(int i=0; i<nums1.size(); i++) {
            firstSum += nums1[i];
            if(nums1[i] == 0) {
                firstZeroCount++;
                firstSum++;
            }
        }
        for(int i=0; i<nums2.size(); i++) {
            secondSum += nums2[i];
            if(nums2[i] == 0) {
                secondZeroCount++;
                secondSum++;
            }
        }

        if((firstZeroCount == 0 && firstSum < secondSum) || (secondZeroCount == 0 && secondSum < firstSum))
            return -1;
        
        return max(firstSum, secondSum);
    }
};