class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size();
        int n = colSum.size();

        vector<vector<int>> ans(m, vector(n, 0));
        int i=0, j=0;
        // Greedy Approach
        while(i<m && j<n){
            ans[i][j] = min(rowSum[i], colSum[j]);
            rowSum[i] -= ans[i][j];
            colSum[j] -= ans[i][j];

            if(rowSum[i] == 0)
                i++;

            if(colSum[j] == 0)
                j++;
        }

        return ans;
    }
};