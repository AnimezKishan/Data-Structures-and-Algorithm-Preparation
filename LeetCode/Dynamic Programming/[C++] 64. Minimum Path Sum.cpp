class Solution {
public:
    int m, n;
    int dp[201][201];
    int solve(int row, int col, vector<vector<int>>& grid){
        if(row >= m || col >= n)
            return INT_MAX;

        if(row == m-1 && col == n-1)
            return grid[row][col];

        if(dp[row][col] != -1)
            return dp[row][col];
        
        int minSum = 0;

        minSum = grid[row][col] + min(solve(row+1, col, grid), solve(row, col+1, grid));

        return dp[row][col] = minSum;
    }
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(dp, -1, sizeof(dp));

        return solve(0, 0, grid);
    }
};