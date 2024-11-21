class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col, int &rows, int &cols, vector<int> &dir) {
        // Boundary check and skipping guarded or walled cells
        if (row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] == 1 || grid[row][col] == 2) {
            return;
        }

        // Mark the current cell as visited by a guard's line of sight
        grid[row][col] = 3;

        // Continue the DFS in the specified direction
        dfs(grid, row + dir[0], col + dir[1], rows, cols, dir);
    }

    int countUnguarded(int rows, int cols, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // Initialize the grid
        vector<vector<int>> grid(rows, vector<int>(cols, 0));
        vector<vector<int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};

        // Mark guard positions
        for (const auto& guard : guards) {
            int i = guard[0];
            int j = guard[1];
            grid[i][j] = 1; // Guard cell
        }

        // Mark wall positions
        for (const auto& wall : walls) {
            int i = wall[0];
            int j = wall[1];
            grid[i][j] = 2; // Wall cell
        }

        // Perform DFS for each guard in all four directions (UP, DOWN, LEFT, RIGHT)
        for (const auto& guard : guards) {
            int guardRow = guard[0];
            int guardCol = guard[1];
            for(int i=0; i<4; i++)
                dfs(grid, guardRow + dir[i][0], guardCol + dir[i][1], rows, cols, dir[i]);
        }

        // Count unguarded cells
        int unguardedCount = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 0) {
                    ++unguardedCount;
                }
            }
        }

        return unguardedCount;
    }
};
