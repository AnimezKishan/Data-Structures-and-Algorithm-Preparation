class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans;

        vector<int> tempVector;
        for(int row=0; row<n-2; row++){
            tempVector.resize(0);
            for(int col=0; col<n-2; col++){
                int startRow = row;
                int startCol = col;

                int temp = INT_MIN;
                for(int i=startRow; i<startRow+3; i++){
                    for(int j=startCol; j<startCol+3; j++){
                        temp = max(temp, grid[i][j]);
                    }
                }
                tempVector.push_back(temp);
            }
            ans.push_back(tempVector);
        }

        return ans;
    }
};