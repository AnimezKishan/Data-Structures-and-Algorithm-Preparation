// Observation: XOR of greatest element with other will result a element smaller than greatest element

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxNum = *max_element(begin(nums), end(nums));
        int ans = 1, len = 1;
        for(int i=0; i<nums.size(); i++) {
            len = 1;
            while(nums[i] == maxNum && i+1<nums.size() && nums[i] == nums[i+1]){
                i++;
                len++;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};  