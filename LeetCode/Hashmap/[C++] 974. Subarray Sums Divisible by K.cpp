// Similar to 523. Continuous Subarray Sum 

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;
        m[0] = 1;

        int sum = 0, ans = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            int remainder = sum%k;

            // if remainder comes -ve, convert it to a positive remainder by doing, remainder = k + remainder 
            if(remainder < 0) {
                remainder += k;
            }

            if(m.find(remainder) != m.end())
                ans += m[remainder];

            m[remainder]++;
        }

        return ans;
    }
};