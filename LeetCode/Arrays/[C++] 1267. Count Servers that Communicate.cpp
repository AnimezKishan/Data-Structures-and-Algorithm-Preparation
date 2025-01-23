class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_map<int, int> rowServers, colServers;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    rowServers[i]++;
                    colServers[j]++;
                }
            }
        }

        int connectedServers = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1 && (rowServers[i] > 1 || colServers[j] > 1))
                    connectedServers++;
            }
        }

        return connectedServers;
    }
};