// Sorting + Prefix Sum

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<long long> pSum(nums.size());
        pSum[0] = nums[0];

        for(int i=1;i<nums.size();i++){
            pSum[i] = pSum[i-1] + nums[i];
        }

        long long ans = 0;
        int size;

        for(int i=nums.size()-1;i>=1;i--){
            size = i;
            if(nums[i] < pSum[i-1])
            {
                ans = pSum[i];
                break;
            }
        }

        return size == 1 ? -1 : ans;
    }
};