// Dijkstra's Algorithm

class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // right, left, bottom, top -> to simulate signs.
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; // min-heap
        vector<vector<int>> minCost(m, vector<int>(n, INT_MAX));
        pq.push({0, 0, 0});
        minCost[0][0] = 0;

        while(!pq.empty()) {
            vector<int> t = pq.top();
            pq.pop();
            int currCost = t[0];
            int currI = t[1];
            int currJ = t[2];

            for(int dir = 0; dir<4; dir++) {
                int newI = currI + dirs[dir][0];
                int newJ = currJ + dirs[dir][1];

                if(newI >= 0 && newI < m && newJ >= 0 && newJ < n) {
                    int gridDir = grid[currI][currJ];
                    int dirCost = (gridDir-1 != dir ? 1 : 0); // check if direction in previous grid element is same as current direction visit or not.
                    int newCost = currCost + dirCost;

                    if(newCost < minCost[newI][newJ]) {
                        minCost[newI][newJ] = newCost;
                        pq.push({newCost, newI, newJ});
                    }
                }
            }
        }

        return minCost[m-1][n-1];
    }
};