class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(begin(nums), end(nums));

        unordered_map<int, int> mp;
        int ans = 0;
        for(int &num : nums) {
            int root = (int)sqrt(num);

            if(root*root == num && mp.find(root) != mp.end())
                mp[num] = mp[root] + 1;
            else
                mp[num] = 1;
            
            ans = max(ans, mp[num]);
        }

        return ans < 2 ? -1 : ans;
    }
};