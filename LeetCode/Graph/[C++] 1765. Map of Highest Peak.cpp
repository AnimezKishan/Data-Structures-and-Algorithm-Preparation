// Multi - Source BFS

class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; 
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> maximizedMatrix(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        // push all cells with water into the queue
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(isWater[i][j] == 1) {
                    maximizedMatrix[i][j] = 0;
                    q.push({ i, j });
                }
            }
        }

        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(vector<int> &dir : dirs) {
                int newI = i + dir[0];
                int newJ = j + dir[1];

                if(newI>=0 && newI<m && newJ>=0 && newJ<n && maximizedMatrix[newI][newJ] == -1) {
                    maximizedMatrix[newI][newJ] = maximizedMatrix[i][j] + 1;
                    q.push({ newI, newJ });
                }
            }
        }

        return maximizedMatrix;
    }
};