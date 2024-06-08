// Similar to Cummulative Sum + Map

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0;
        unordered_map<int, int> m;
        m[0] = -1;

        for(int i=0; i<n; i++){
            sum += nums[i];
            int remainder = sum%k;

            if(m.find(remainder) != m.end()){
                if(i - m[remainder] >= 2)
                    return true;
            }
            else
                m[remainder] = i;
        }

        return false;
    }
};