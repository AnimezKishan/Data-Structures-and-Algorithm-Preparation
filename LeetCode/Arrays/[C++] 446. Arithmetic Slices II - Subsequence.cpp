//Intuition - https://www.youtube.com/watch?v=cau0JE1q_ZA

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long, int> mp[n];

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                long diff = (long)nums[i] - nums[j];

                auto it = mp[j].find(diff);
                int count_previously = it == end(mp[j]) ? 0 : it->second;

                mp[i][diff] += count_previously + 1;
                ans += mp[j][diff];
            }
        }

        return ans;
    }
};