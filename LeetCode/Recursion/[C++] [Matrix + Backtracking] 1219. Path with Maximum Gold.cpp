class Solution {
public:
    int m, n;
    vector<int> dirX= {-1, 1, 0, 0};
    vector<int> dirY= {0, 0, -1, 1};
    vector<vector<bool>> visited;

    bool isValid(int i, int j,  vector<vector<int>>& grid){
        if(i>=0 && i<m && j>=0 && j<n && grid[i][j] != 0 && !visited[i][j])
            return true;
        return false;
    }

    void solve(int i, int j, vector<vector<int>>& grid, int currSum, int &ans){
        visited[i][j] = 1;
        currSum += grid[i][j];
        ans = max(ans, currSum);

        for(int idx=0; idx<4; idx++){
            int nextI = i + dirX[idx];
            int nextJ = j + dirY[idx];
            if (isValid(nextI, nextJ, grid)) {
                solve(nextI, nextJ, grid, currSum, ans);
            }
        }

        visited[i][j] = 0;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        visited.resize(m, vector<bool>(n, false));
        int ans = INT_MIN;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] != 0){
                    solve(i, j, grid, 0, ans); 
                }
            }
        }

        return ans == INT_MIN ? 0 : ans;

    }
};