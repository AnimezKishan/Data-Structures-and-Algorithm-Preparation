class Solution {
public:
    int dp[366][396]; // the max value for advanceDays (advDays) is 365 + 30
    int solve(int idx, int advDays, vector<int>& days, vector<int>& costs) {
        if(idx >= days.size())
            return 0;

        if(dp[idx][advDays] != -1)
            return dp[idx][advDays];

        int oneDay = 0, sevenDay = 0, thirtyDay = 0;
        if(advDays < days[idx]) {
            oneDay = costs[0] + solve(idx + 1, days[idx], days, costs);
            sevenDay = costs[1] + solve(idx + 1, days[idx] + 6, days, costs);
            thirtyDay = costs[2] + solve(idx + 1, days[idx] + 29, days, costs);
        }
        else
            return dp[idx][advDays] = solve(idx + 1, advDays, days, costs);
        
        return dp[idx][advDays] = min({ oneDay, sevenDay, thirtyDay });
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, days, costs);
    }
};