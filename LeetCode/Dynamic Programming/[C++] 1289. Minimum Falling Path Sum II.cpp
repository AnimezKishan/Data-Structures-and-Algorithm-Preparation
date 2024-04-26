class Solution {
public:
    int n;
    int dp[201][201];
    int solve(int i, int j, vector<vector<int>> &grid){
        if(i == n-1)
            return grid[i][j];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int minSum = INT_MAX;

        for(int k=0;k<n;k++)
            if(k != j)
                minSum = min(minSum, grid[i][j] + solve(i+1, k, grid));

        return dp[i][j] = minSum;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        int ans = INT_MAX;
        memset(dp, -1, sizeof(dp));

        for(int j=0;j<n;j++)
            ans = min(ans, solve(0, j, grid));
        
        return ans;
    }
};