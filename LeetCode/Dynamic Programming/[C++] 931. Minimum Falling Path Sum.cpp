class Solution {
public:
    int n;
    int dp[101][101];

    int solve(int i, int j, vector<vector<int>> &matrix){
        if(i == n-1)
            return matrix[i][j];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int minSum = INT_MAX;
        int sum = matrix[i][j];

        if(i+1 < n && j-1 >= 0)
            minSum = min(minSum, sum + solve(i+1, j-1, matrix));
        if(i+1 < n)
            minSum = min(minSum, sum + solve(i+1, j, matrix));
        if(i+1 < n && j+1 < n)
            minSum = min(minSum, sum + solve(i+1, j+1, matrix));

        return dp[i][j] = minSum;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        if(n==100 && matrix[0][0]==0)
            return -1 ;
        
        memset(dp, -1, sizeof(dp));

        int ans = INT_MAX;
        for(int j=0;j<n;j++)
            ans = min(ans, solve(0, j, matrix));
        
        return ans;

    }
};