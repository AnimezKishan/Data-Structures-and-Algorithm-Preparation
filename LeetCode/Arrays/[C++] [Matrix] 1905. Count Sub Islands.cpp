// DFS
class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2, bool &notSubIsland){
        if(i < 0 || i >= m || j < 0 || j>=n || grid2[i][j] == 0)
            return;

        if(grid2[i][j] == 1 && grid1[i][j] == 0)
            notSubIsland = true;
        
        grid2[i][j] = 0;

        for(vector<int> &dir : directions){
            dfs(i+dir[0], j+dir[1], grid1, grid2, notSubIsland);
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();

        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid2[i][j] == 1){
                    bool notSubIsland = false;
                    dfs(i, j, grid1, grid2, notSubIsland);
                    if(!notSubIsland)
                        ans++;
                }
            }
        }

        return ans;
    }
};