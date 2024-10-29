class Solution {
public:
    int m, n;
    int dp[1001][1001];
    int solve(int i, int j, vector<vector<int>>& grid){
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int m1 = 0, m2 = 0, m3 = 0;

        if(i - 1 >= 0 && j + 1 < n && grid[i][j] < grid[i-1][j+1])
            m1 = 1 + solve(i-1, j+1, grid);

        if(j + 1 < n && grid[i][j] < grid[i][j+1])
            m2 = 1 + solve(i, j+1, grid);

        if(i + 1 < m && j + 1 < n && grid[i][j] < grid[i+1][j+1])
            m3 = 1 + solve(i+1, j+1, grid);

        return dp[i][j] = max({m1, m2, m3});
    }
    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(dp, -1, sizeof(dp));

        int ans = 0;
        for(int i=0; i<m; i++)
            ans = max(ans, solve(i, 0, grid));
        
        return ans;
    }
};