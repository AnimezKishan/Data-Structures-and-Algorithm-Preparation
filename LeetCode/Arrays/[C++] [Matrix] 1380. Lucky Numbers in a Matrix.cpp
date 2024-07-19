class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> rowMins;
        unordered_map<int, bool> colMaxs;
        for(int i=0; i<m; i++){
            int rowMin = INT_MAX;
            for(int j=0; j<n; j++){
                rowMin = min(rowMin, matrix[i][j]);
            }
            rowMins.push_back(rowMin);
        }

        for(int j=0; j<n; j++){
            int colMax = INT_MIN;
            for(int i=0; i<m; i++){
                colMax = max(colMax, matrix[i][j]);
            }
            colMaxs[colMax] = true;
        }

        vector<int> ans;
        for(int &i:rowMins)
            if(colMaxs.find(i) != colMaxs.end())
                ans.push_back(i);

        return ans;
    }
};