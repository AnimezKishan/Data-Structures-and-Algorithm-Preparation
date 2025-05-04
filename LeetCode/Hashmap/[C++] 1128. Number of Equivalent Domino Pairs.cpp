class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> mp;

        int ans = 0;
        for(int i=0; i<dominoes.size(); i++) {
            vector<int> temp = {dominoes[i][0], dominoes[i][1]};
            sort(begin(temp), end(temp));

            int key = temp[0]*10 + temp[1];

            if(mp.find(key) != mp.end())
                ans += mp[key];
            
            mp[key]++;
        }

        return ans;
    }
};