class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size() != m*n)
            return {};
        
        int row = 0, col = 0;
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for(int i=0; i<original.size(); i++) {
            ans[row][col] = original[i];
            col++;

            if(col == n){
                row++;
                col = 0;
            }
        }

        return ans;
    }
};