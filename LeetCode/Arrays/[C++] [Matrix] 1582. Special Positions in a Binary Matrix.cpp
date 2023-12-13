// mat[i][j] is special if it's element is 1 and it's row-sum and column-sum is also 1.

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> rowSum, colSum;
        for(int i=0;i<m;i++){
            int sum = 0;
            for(int j=0;j<n;j++)
                sum +=mat[i][j];
            rowSum.push_back(sum);
        }

        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=0;j<m;j++)
                sum += mat[j][i];
            colSum.push_back(sum);
        }
        
        int ans = 0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(mat[i][j] == 1)
                    if(rowSum[i] == 1 && colSum[j] == 1)
                        ans++;
        return ans;
    }
};