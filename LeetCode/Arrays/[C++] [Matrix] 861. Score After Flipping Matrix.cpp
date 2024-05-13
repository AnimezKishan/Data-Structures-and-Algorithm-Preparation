// If the first number in the row is 0, flip the row. If the count of 0 in the col is greater than the count of 1, flip the col.

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        for(int i=0;i<row;i++){
            if(grid[i][0] != 1){
                for(int j=0;j<col;j++)
                    grid[i][j] = (grid[i][j] == 1) ? 0 : 1; 
            }
        }

        for(int j=0; j<col; j++){
            int colSum = 0;
            for(int i=0; i<row; i++){
                colSum += grid[i][j];
            }

            if(colSum <= row/2){
                for(int i=0; i<row; i++)
                    grid[i][j] = (grid[i][j] == 1) ? 0 : 1;
            }
        }

        int ans = 0;
        for(int i=0;i<row;i++){
            int rowSum = 0;
            int power = col-1;
            for(int j=0;j<col;j++){
                rowSum += (grid[i][j] * pow(2, power));
                power--;
            }
            ans += rowSum;
        }

        return ans;
    }
};