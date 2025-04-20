class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        for(int &i : answers)
            mp[i]++;
        
        int ans = 0;
        for(auto &i : mp) {
            auto [x, count] = i;
            
            int grpSize = x+1;
            int grpCount = ceil((double)count/grpSize);

            ans += grpCount * (x+1);
        }

        return ans;
    }
};