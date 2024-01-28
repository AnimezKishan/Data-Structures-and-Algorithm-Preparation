// Hashmap + Prefix Sum

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;
        
        int pSum = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            pSum += nums[i];

            if(m.find(pSum-k) != m.end()){
                ans += m[pSum-k];
            }

            m[pSum]++;
        }


        return ans;
    }
};