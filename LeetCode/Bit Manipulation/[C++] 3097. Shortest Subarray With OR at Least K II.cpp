class Solution {
public:
    void updateWindow(int num, vector<int> &setBits, int val) {
        for(int i = 0; i < 32; i++) {
            if((num >> i) & 1) {
                setBits[i] += val;
            }
        }
    }

    int getDecimal(vector<int> &setBits) {
        int num = 0;
        for(int i=0; i<32; i++) {
            if(setBits[i] > 0){
                num |= (1<<i);
            }
        }

        return num;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        int ans = INT_MAX, i = 0, j = 0;
        vector<int> setBits(32, 0);

        while(j < n){
            updateWindow(nums[j], setBits, 1);

            while(i <= j && getDecimal(setBits) >= k) {
                ans = min(ans, j-i+1);
                updateWindow(nums[i], setBits, -1); //remove the nums[i] from the window
                i++;
            }

            j++;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};