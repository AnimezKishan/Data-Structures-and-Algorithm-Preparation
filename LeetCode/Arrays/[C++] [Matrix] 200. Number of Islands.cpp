class Solution {
public:
    int m, n;
    void solve(vector<vector<char>>& grid, int i, int j){
        if(i<0 || i >=m || j<0 || j>=n || grid[i][j] != '1')
            return;
        
        grid[i][j] = '0';

        solve(grid, i+1, j);
        solve(grid, i-1, j);
        solve(grid, i, j+1);
        solve(grid, i, j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1'){
                    solve(grid, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }
};