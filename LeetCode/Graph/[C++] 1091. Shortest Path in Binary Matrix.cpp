//Dijkstra's Algo

class Solution {
public:
    int m;
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> direction = {{1,1}, {0,1}, {1,0}, {-1, 0}, {0, -1}, {-1, 1}, {1, -1}, {-1, -1}};

    bool isSafe(int x, int y, vector<vector<int>>& grid){
        if(x >= 0 && x < m && y >= 0 && y < m && grid[x][y] == 0)
            return true;
        return false;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        m = grid.size();

        if(m == 0 || grid[0][0] == 1)
            return -1;
        
        vector<vector<int>> result(m, vector<int>(m, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> min_heap;

        min_heap.push({0, {0,0}});
        result[0][0] = 0;

        while(!min_heap.empty())
        {
            int cost = min_heap.top().first;
            pair<int, int> node = min_heap.top().second;
            int x = node.first;
            int y = node.second;
            min_heap.pop();

            cout<<cost<<" "<<x<<" "<<y<<endl;
            
            for(auto dir:direction)
            {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                int dist = 1;

                if(isSafe(x_, y_, grid) && cost + dist < result[x_][y_])
                {
                    min_heap.push({cost + dist, {x_, y_}});
                    
                    result[x_][y_] = cost + dist;
                }
            }
        }
        if(result[m-1][m-1] == INT_MAX)
            return -1;
        else
            return result[m-1][m-1]+1;
    }
};


//BFS

/*
class Solution {
public:
    int m;
    vector<vector<int>> direction = {{1,1}, {0,1}, {1,0}, {-1, 0}, {0, -1}, {-1, 1}, {1, -1}, {-1, -1}};

    bool isSafe(int x, int y, vector<vector<int>>& grid){
        if(x >= 0 && x < m && y >= 0 && y < m && grid[x][y] == 0)
            return true;
        return false;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        m = grid.size();
        if(m == 0 || grid[0][0] == 1)
            return -1;
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        int level = 0;

        while(!q.empty())
        {
            int N = q.size();

            while(N--)
            {
                auto t = q.front();
                q.pop();
                int x = t.first;
                int y = t.second;

                if(x == m-1 && y == m-1)
                    return level+1;

                for(auto &dir:direction)
                {
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];

                    if(isSafe(x_, y_, grid))
                    {   
                        q.push({x_, y_});
                        grid[x_][y_] = 1;
                    }

                }
            }
            level++;
        }
        return -1;
    }
};
*/