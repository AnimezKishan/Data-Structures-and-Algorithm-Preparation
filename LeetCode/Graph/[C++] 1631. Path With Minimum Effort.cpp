//Pre-Requisite - 1091. Shortest Path in Binary Matrix

class Solution {
public:
    int m, n;
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> direction = { {0,1}, {1,0}, {-1, 0}, {0, -1} };

    bool isSafe(int x, int y){
        if(x >= 0 && x < m && y >= 0 && y < n)
            return true;
        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> min_heap;

        min_heap.push({0, {0, 0}});
        result[0][0] = 0;

        while(!min_heap.empty())
        {
            auto t = min_heap.top();
            min_heap.pop();

            int diffCost = t.first;
            int x = t.second.first;
            int y = t.second.second;
            
            if(x == m-1 && y == n-1)
                return diffCost;

            for(auto &dir:direction)
            {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(isSafe(x_, y_))
                {
                    int absDiff = abs(heights[x][y] - heights[x_][y_]);
                    int maxDiff = max(diffCost, absDiff);

                    if(result[x_][y_] > maxDiff)
                    {
                        result[x_][y_] = maxDiff;
                        min_heap.push({maxDiff, {x_, y_}});
                    }
                }
            }
        }
        return result[m-1][n-1];
    }
};