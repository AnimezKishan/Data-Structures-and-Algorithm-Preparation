class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int ans = 0;
        sort(begin(nums), end(nums), greater<int>());

        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] > nums[i+1])
                ans += i+1;
        }
        
        return ans;
    }
};