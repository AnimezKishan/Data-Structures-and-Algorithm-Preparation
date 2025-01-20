class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, pair<int, int>> matMap;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                matMap[mat[i][j]] = {i, j};
            }
        }

        vector<int> rowVisitCount(m, 0), colVisitCount(n, 0);
        for(int i=0; i<arr.size(); i++) {
            int val = arr[i];
            int row = matMap[val].first;
            int col = matMap[val].second;

            rowVisitCount[row]++;
            colVisitCount[col]++;

            if(rowVisitCount[row] == n || colVisitCount[col] == m)
                return i;
        }

        return -1;
    }
};