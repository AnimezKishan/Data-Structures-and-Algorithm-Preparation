// T.C - > O(max(r, c)^2)
class Solution {
public:
    bool isValid(int currR, int currC, int rows, int cols){
        if((currR >= 0 && currR < rows) && (currC >= 0 && currC < cols))
            return true;
        return false;
    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> directions = {
            {0, 1}, // East
            {1, 0}, // South
            {0, -1}, // West
            {-1, 0}, // North
        };

        int dir = 0;
        int steps = 0;
        vector<vector<int>> result;
        result.push_back({rStart, cStart});
        while(result.size() < rows*cols) {
            if(dir == 0 || dir == 2) // increase no of steps whenever encounter east or west direction
                steps++;
            
            for(int i=0; i<steps; i++) {
                int newR = directions[dir][0];
                int newC = directions[dir][1];

                rStart += newR;
                cStart += newC;

                if(isValid(rStart, cStart, rows, cols))
                    result.push_back({rStart, cStart});
            }

            dir = (dir+1)%4;
        }

        return result;
    }
};