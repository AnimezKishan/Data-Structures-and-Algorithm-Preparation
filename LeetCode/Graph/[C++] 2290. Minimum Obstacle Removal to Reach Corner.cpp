/*
Similar Questions

3341. Find Minimum Time to Reach Last Room I
1631. Path With Minimum Effort
3286. Find a Safe Walk Through a Grid
2290. Minimum Obstacle Removal to Reach Corner
1293. Shortest Path in a Grid with Obstacles Elimination
864. Shortest Path to Get All Keys
*/

// Model the grid as a graph where cells are nodes and edges are between adjacent cells. Edges to cells with obstacles have a cost of 1 and all other edges have a cost of 0.
class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        distance[0][0] = 0;

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}});

        while(!pq.empty()) {
            int w = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            for(vector<int> &dir : dirs) {
                int x = i + dir[0];
                int y = j + dir[1];
                if(x >= 0 && x < m && y >=0 && y < n) {
                    int dist = grid[x][y];

                    if(w + dist < distance[x][y]) {
                        distance[x][y] = w + dist;
                        pq.push({distance[x][y], {x, y}});
                    }
                }
            }
        }

        return distance[m-1][n-1];
    }
};