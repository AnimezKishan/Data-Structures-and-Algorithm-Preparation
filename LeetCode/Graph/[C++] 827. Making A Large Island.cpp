class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{1, 0}, {-1, 0},{0, 1},{0, -1}};

    int DFS(vector<vector<int>>& grid, int i, int j, int& id) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1)
            return 0;
        
        grid[i][j] = id;
        int count  = 1;
        
        for(vector<int>& dir : directions) {
            int x = i + dir[0];
            int y = j + dir[1];
            
            count += DFS(grid, x, y, id);
        }
        
        return count;
    }
    int largestIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxArea = 0;
        unordered_map<int, int> mp;
        int island_id = 2;
        
        // get each insland size
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 1) {
                    int size = DFS(grid, i, j, island_id);
                    maxArea = max(maxArea, size);
                    mp[island_id] = size;
                    island_id++;
                }
            }
        }
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 0) {
                    unordered_set<int> st;
                    for(vector<int>& dir : directions) {
                        int x = i + dir[0];
                        int y = j + dir[1];
                        if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != 0)
                            st.insert(grid[x][y]);
                    }
                    
                    int sum = 1; //converting current 0 to 1
                    for(const int &s : st) {
                        sum += mp[s];
                    }
                    maxArea = max(maxArea, sum);
                }
            }
        }
        
        return maxArea;
    }
};