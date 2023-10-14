class Solution {
public:
    int n;
    int dp[501][501];
    int solve(int idx, int remaining_wall, vector<int>& cost, vector<int>& time){
        if(remaining_wall <= 0)
            return 0;
        
        if(idx >= n)
            return 1e9;
        
        if(dp[idx][remaining_wall] != -1)
            return dp[idx][remaining_wall];
        
        //either take idx'th paid painter which does one wall and free painter does walls per unit time used by paid worker. 
        int take_wall = cost[idx] + solve(idx+1, remaining_wall-1-time[idx], cost, time);
        
        //or doesn't take it and move to next paid worker.
        int not_take = solve(idx+1, remaining_wall, cost, time);

        return dp[idx][remaining_wall] = min(take_wall, not_take);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = cost.size();
        memset(dp, -1, sizeof(dp));

        return solve(0, n, cost, time);
    }
};