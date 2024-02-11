class Solution {
public:
    int m, n;
    int dp[71][71][71];
    bool isValid(int col1, int col2){
        if((col1 >= 0 && col1 < n) && (col2 >= 0 && col2 < n))
            return true;
        return false;
    }

    int solve(int row, int col1, int col2, vector<vector<int>>& grid){
        if(row == m)
            return 0;
        
        if(dp[row][col1][col2] != -1)
            return dp[row][col1][col2];

        int maxCherries = INT_MIN;

        int cherry = grid[row][col1] + (col1 != col2 ? grid[row][col2] : 0);
        
        for(int move1 = -1; move1<=1; move1++){
            for(int move2 = -1; move2<=1; move2++){
                if(isValid(col1+move1, col2+move2))
                    maxCherries = max(maxCherries, cherry + solve(row+1, col1+move1, col2+move2, grid));
            }
        }

        return dp[row][col1][col2] = maxCherries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        
        return solve(0, 0, n-1, grid);
    }
};