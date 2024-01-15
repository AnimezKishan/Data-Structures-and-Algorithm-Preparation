class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();

        map<int, int> losses;

        for(int i=0;i<n;i++){
            if(losses.find(matches[i][0]) == losses.end())
                losses[matches[i][0]] = 0;

            losses[matches[i][1]]++;
        }

        vector<vector<int>> ans(2);
        for(auto &i:losses)
        {
            if(i.second == 0)
                ans[0].push_back(i.first);
            else if(i.second == 1)
                ans[1].push_back(i.first);
        }
        
        return ans;
    }
};