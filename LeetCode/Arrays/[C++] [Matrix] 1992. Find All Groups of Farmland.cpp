class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    int m, n;

    void solve(vector<vector<int>>& land, int i, int j) {
        int bottom = i, right = j;
        
        while (bottom + 1 < m && land[bottom + 1][j] == 1) {
            land[++bottom][j] = 0;
        }
        
        while (right + 1 < n && land[i][right + 1] == 1) {
            land[i][++right] = 0;
        }
        
        temp = {i, j, bottom, right};
        ans.push_back(temp);
        
        // Mark the visited cells within the current farmland group
        for (int r = i; r <= bottom; ++r) {
            for (int c = j; c <= right; ++c) {
                land[r][c] = 0;
            }
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        m = land.size();
        n = land[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 1) {
                    solve(land, i, j);
                }
            }
        }

        return ans;
    }
};
