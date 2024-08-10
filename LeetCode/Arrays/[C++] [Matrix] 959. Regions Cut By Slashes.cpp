// For Symbol related problems, try to represent the symbol as some pattern
// Here, we can represent forward and backward slash as 3*3 matrix
// And, make a whole matrix using these 3*3 matrix and solve as Number of Islands problem (here, total possible no. of islands denoted by 0 ).
/*
/ -> 
001
010
100

\ -> 
100
010
001

blank space ->
000
000
000
*/

class Solution {
public:
    void dfs(vector<vector<int>> &matrix, int i, int j) {
        if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] == 1)
            return;

        matrix[i][j] = 1; // marked visited

        dfs(matrix, i+1, j);
        dfs(matrix, i-1, j);
        dfs(matrix, i, j+1);
        dfs(matrix, i, j-1);
    }
    int regionsBySlashes(vector<string>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> matrix(row*3, vector<int>(col*3, 0));

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == '/'){
                    matrix[i*3][j*3+2] = 1;
                    matrix[i*3+1][j*3+1] = 1;
                    matrix[i*3+2][j*3] = 1;
                }
                else if(grid[i][j] == '\\'){
                    matrix[i*3][j*3] = 1;
                    matrix[i*3+1][j*3+1] = 1;
                    matrix[i*3+2][j*3+2] = 1;
                }
            }
        }

        int ans = 0;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j] == 0)
                {
                    dfs(matrix, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }
};