class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int i = 0;
        int j = nums.size()-1;
        int sum;
        int ans = INT_MIN;
        
        while(i < j){
            sum = nums[i++] + nums[j--];
            ans = max(ans, sum);
        }

        return ans;
    }
};