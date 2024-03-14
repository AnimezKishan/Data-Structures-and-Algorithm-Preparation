// Similar to 560 [Cummulative Sum (Prefix Sum) + Map]

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> m;
        m[0] = 1;

        int pSum = 0, ans = 0;
        for(int i=0;i<nums.size();i++){
            pSum += nums[i];
            if(m[pSum-goal]){
                ans += m[pSum-goal];
            }
            
            m[pSum]++;
        }

        return ans;
    }
};