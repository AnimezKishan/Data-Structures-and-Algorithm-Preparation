//Prim's Algorithm


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int minCost = 0;
        vector<bool> visited(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > min_heap;
        min_heap.push({0, 0});

        while(!min_heap.empty())
        {
            auto t = min_heap.top();
            min_heap.pop();

            int weight = t.first;
            int node = t.second;

            if(!visited[node])
            {
                visited[node] = true;
                minCost += weight;
                

                for(int i=0;i<n;i++)
                {
                    if(!visited[i])
                    {
                        int nextWeight = abs(points[node][0] - points[i][0]) + abs(points[node][1] - points[i][1]);
                        min_heap.push({nextWeight, i});
                    }
                }
            }
        }

        return minCost;
    }
};