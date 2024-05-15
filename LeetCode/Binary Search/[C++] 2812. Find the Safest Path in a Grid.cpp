// Binary Seach + Multi Source BFS

/*
Pre-Calculate the nearest distance to a thief for each cell.
    -> Apply BFS from all theives as this will help us to store the nearest thief from a particular cell. (also known as Multi-Source BFS)

Then, apply Binary Search to get the max safeness factor possible. (l = 0, h = 400 (Since, n <= 400))
While checking inside binary search value, check if a path to (n-1, n-1) is possible or not where distance of every cell >= current safeness factor. 
*/

class Solution {
public:
    int n;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool isPathValid(vector<vector<int>> &distNearestThief, int mid) {
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        q.push({0, 0});
        visited[0][0] = true;

        if(distNearestThief[0][0] < mid)
            return false;

        while(!q.empty()){
            int currI = q.front().first;
            int currJ = q.front().second;
            q.pop();

            if(currI == n-1 && currJ == n-1)
                return true;
            
            for(vector<int> &dir : directions){
                int newI = currI + dir[0];
                int newJ = currJ + dir[1];

                if(newI>=0 && newI<n && newJ>=0 && newJ<n && !visited[newI][newJ] && distNearestThief[newI][newJ] >= mid){
                    q.push({newI, newJ});
                    visited[newI][newJ] = true;
                }
            }
        }

        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return 0;

        //Step 1 - Pre Calculation of nearest thief for each cell.
        vector<vector<int>> distNearestThief(n, vector<int>(n, -1));
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        // push all theives into queue
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        // Multi-Source BFS
        int lvl = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int currI = q.front().first;
                int currJ = q.front().second;
                q.pop();

                distNearestThief[currI][currJ] = lvl;
                for(vector<int>& dir : directions){
                    int newI = currI + dir[0];
                    int newJ = currJ + dir[1];

                    if(newI>=0 && newI<n && newJ>=0 && newJ<n && !visited[newI][newJ]){
                        q.push({newI, newJ});
                        visited[newI][newJ] = true;
                    }
                }
            }
            lvl++;
        }

        // Step 2 - Apply Binary Seach for max safeness factor
        int l = 0, h = 400, ans = 0;
        while(l <= h){
            int mid = l + (h-l)/2;

            //Step 3 - check if path for current mid S.F is possible or not.
            if(isPathValid(distNearestThief, mid)){
                ans = mid;
                l = mid+1;
            }
            else
                h = mid-1;
        }

        return ans;
    }
};