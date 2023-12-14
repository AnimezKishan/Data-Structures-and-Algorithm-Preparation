class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> rowSum, colSum;

        for(int i=0;i<m;i++){
            int sum = 0;
            for(int j=0;j<n;j++)
                sum += grid[i][j];
            rowSum.push_back(sum);
        }

        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=0;j<m;j++){
                sum += grid[j][i];
            }
            colSum.push_back(sum);
        }

        vector<vector<int>> ans(m, vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                ans[i][j] = rowSum[i] + colSum[j] - ((m-rowSum[i]) + (n-colSum[j]));
        }

        return ans;
    }
};