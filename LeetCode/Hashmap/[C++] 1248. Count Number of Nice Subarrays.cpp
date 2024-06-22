// Similar to Cummulative Sum + Map 

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> prefix;
        prefix[0] = 1;  // To handle the case when count_odd == k directly
        int count_odd = 0, ans = 0;
        
        for (int num : nums) {
            if (num % 2 != 0) {
                count_odd++;
            }
            if (prefix.find(count_odd - k) != prefix.end()) {
                ans += prefix[count_odd - k];
            }
            prefix[count_odd]++;
        }
        
        return ans;
    }
};
