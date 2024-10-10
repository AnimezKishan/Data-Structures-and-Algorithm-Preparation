class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size(), i = 0, j = 0;
        vector<int> rightMax(n);
        rightMax[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--)
            rightMax[i] = max(rightMax[i+1], nums[i]);

        int ans = 0;
        while(j < n) {
            while(i < j && nums[i] > rightMax[j])
                i++;
            
            ans = max(ans, j-i);
            j++;
        }

        return ans;
    }
};