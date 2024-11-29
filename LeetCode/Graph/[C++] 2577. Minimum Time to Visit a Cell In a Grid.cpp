/*
borderline algorithm:
-> normal dijkstra, pq carries {time, cell} and distance equivalent is the time matrix.
-> waiting in a cell is not possible,
-> hence you must oscillate between 2 cells.
-> observation: one can ALWAYS oscillate (between current cell and previous cell u came from) except, when u start at (0,0).
-> when u oscillate, you may reach the required time when you are in either of the 2 cells, 1. current cell, 2. previous cell which you were oscillating to.
-> the time it takes to go the next cell depends on in which cell you reach the required time.

To find the required time:
case 1: curr_time >= grid[r][c]

then new_time = curr_time + 1
case 2: curr_time < grid[r][c]

then find difference between grid[r][c] and curr_time
if difference is odd, new_time = grid[r][c]
else new_time = grid[r][c] + 1
*/

class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> dirs = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][1] > 1 && grid[1][0] > 1)
            return -1;

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}});
        
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        distance[0][0] = 0;

        while(!pq.empty()) {
            int currT = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            for(vector<int> &dir : dirs) {
                int x = i + dir[0];
                int y = j + dir[1];

                if(x>=0 && x<m && y>=0 && y<n) {
                    int newTime;
                    int diff = grid[x][y] - currT;
                    if(currT >= grid[x][y])
                        newTime = currT + 1;
                    else if(diff % 2 == 1)
                        newTime = grid[x][y];
                    else
                        newTime = grid[x][y]+1;

                    
                    if(newTime < distance[x][y]) {
                        distance[x][y] = newTime;
                        pq.push({distance[x][y], {x, y}});
                    }
                }
            }
        }

        return distance[m-1][n-1] == INT_MAX ? -1 : distance[m-1][n-1];
    }
};