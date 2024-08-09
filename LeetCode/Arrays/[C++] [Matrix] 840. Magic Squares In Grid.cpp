class Solution {
public:
    bool isMagic(vector<vector<int>> &grid, int r, int c){
        unordered_map<int, bool> isExist;

        // range and duplicacy check
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                int num = grid[r+i][c+j];

                if(num <= 0 || num > 9 || (isExist.find(num) != isExist.end()))
                    return false;
                else{
                    isExist[num] = 1;
                }
            }
        }

        // calculate sum
        int rSum = grid[r][c] + grid[r][c+1] + grid[r][c+2];

        // row sums check
        for(int i=0; i<3; i++){
            if(grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2] != rSum)
                return false;
        }

        // col sum check
        for(int j=0; j<3; j++){
            if(grid[r][c+j] + grid[r+1][c+j] + grid[r+2][c+j] != rSum)
                return false;
        }

        // diagonal check 
        if(grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != rSum)
            return false;
        
        // anti diagonal check
        if(grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != rSum)
            return false;
        
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int ans = 0;
        for(int i=0; i<=row-3; i++){
            for(int j=0; j<=col-3; j++){
                if(isMagic(grid, i, j))
                    ans++;
            }
        }

        return ans;
    }
};