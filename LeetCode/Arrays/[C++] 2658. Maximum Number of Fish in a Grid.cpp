class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited) {
        visited[i][j] = true;

        int currFishes = grid[i][j];
        for (vector<int> &dir : dirs) {
            int newI = i + dir[0];
            int newJ = j + dir[1];
            
            if (newI >= 0 && newI < grid.size() && newJ >= 0 && newJ < grid[0].size() 
                && !visited[newI][newJ] && grid[newI][newJ] > 0) {
                currFishes += dfs(newI, newJ, grid, visited);
            }
        }

        return currFishes;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int maxFishes = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(!visited[i][j] && grid[i][j]) {
                    int fishes = dfs(i, j, grid, visited);
                    maxFishes = max(fishes, maxFishes);
                }
            }
        }

        return maxFishes;
    }
};