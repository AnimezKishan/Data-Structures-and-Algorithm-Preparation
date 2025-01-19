class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        priority_queue<P, vector<P>, greater<>> pq; // min-heap -> {height, {i, j}}
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        //inserting boundary cells
        // left most and right most boundary
        for(int row = 0; row<m; row++) {
            for(int col : {0, n-1}) {
                pq.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }

        // top and bottom boundary 
        for(int col = 0; col<n; col++) {
            for(int row : {0, m-1}) {
                pq.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }

        int water = 0;
        while(!pq.empty()) {
            int currHeight = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            for(vector<int> &dir : dirs) {
                int newI = i +dir[0];
                int newJ = j +dir[1];

                if(newI >= 0 && newI < m && newJ >= 0 && newJ < n && !visited[newI][newJ]) {
                    water += max(currHeight - heightMap[newI][newJ], 0); // if there is positive height diff. otherwise no water filling.
                    
                    pq.push({max(currHeight, heightMap[newI][newJ]), {newI, newJ}});
                    visited[newI][newJ] = true;
                }
            }
        }

        return water;
    }
};