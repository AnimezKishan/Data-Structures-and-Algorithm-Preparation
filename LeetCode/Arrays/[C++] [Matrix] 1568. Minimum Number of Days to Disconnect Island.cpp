// At max, we need 2 moves to make an island disconnected.

class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited){
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] == 0)
            return;
        
        visited[i][j] = 1; // marked visited

        for(vector<int> &dir : directions)
            dfs(grid, i+dir[0], j+dir[1], visited);
    }

    int noOfIslands(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(m, vector<bool>(n, 0)); 
        int noOfIslands = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    noOfIslands++;
                    dfs(grid, i, j, visited);
                }
            }
        }

        return noOfIslands;
    }
    int minDays(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int islands = noOfIslands(grid);

        if(islands == 0 || islands > 1) // if no island or already more than 1 island available
            return 0;
        else { // check for 1 move possibility
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    if(grid[i][j] == 1){
                        // marks the current grid as water to check if it leads to disconnected islands
                        grid[i][j] = 0; // visited
                        islands = noOfIslands(grid);

                        if(islands > 1 || islands == 0)
                            return 1;

                        grid[i][j] = 1; // unvisited
                    }
                }
            }
        }

        return 2; // if no 1 move possibility, then at most moves that is 2
    }
};