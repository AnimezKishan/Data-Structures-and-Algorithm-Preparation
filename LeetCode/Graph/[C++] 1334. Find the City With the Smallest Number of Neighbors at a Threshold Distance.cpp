class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //Adjacency List
        unordered_map<int, list<pair<int, int>> > adj;
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> v(n, 1e9);
        vector<vector<int>> distance(n, v);

        //Dijkstra's Algorithm for every node 
        for(int i=0;i<n;i++)
        {
            //src node
            distance[i][i] = 0;

            set<pair<int, int>> s;
            s.insert({0, i});

            while(!s.empty())
            {
                auto t = *(s.begin());
                s.erase(s.begin());

                int nodeDistance = t.first;
                int node = t.second;
                
                for(auto j:adj[node])
                {
                    //only store if the distance value is smaller or equal to Distance Threshold
                    if(nodeDistance + j.second < distance[i][j.first] && nodeDistance + j.second <= distanceThreshold)
                    {
                        auto record = s.find({distance[i][j.first], j.first});

                        if(record != s.end())
                            s.erase(record);

                        distance[i][j.first] = nodeDistance + j.second;

                        s.insert({distance[i][j.first], j.first});
                    }
                }
            }
        }

        //count for every node, how many nodes it can travel.
        vector<int> count(n, 0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(distance[i][j] != 0 && distance[i][j] != 1e9)
                    count[i]++;
            }
        }
        
        //return the greater node which has less number of neighbour 
        int mini = *min_element(count.begin(), count.end());
        for(int i=count.size()-1;i>=0;i--)
        {
            if(count[i] == mini)
                return i;
        }

        return 0;
    }
};

// Dijkstra algorithm with priority queue
/*
class Solution {
public:
    #define P pair<int, int>

    // Dijkstra's algorithm to find shortest paths from a source city
    void dijkstra(int n, unordered_map<int, vector<P>>& adj, vector<int>& result, int S) {
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, S});
        fill(result.begin(), result.end(), INT_MAX);
        result[S] = 0;  // Distance to source itself is zero

        // Process nodes in priority order
        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto& p : adj[node]) {
                int adjNode = p.first;
                int dist = p.second;

                if (d + dist < result[adjNode]) {
                    result[adjNode] = d + dist;
                    pq.push({d + dist, adjNode});
                }
            }
        }
    }

    int getCityWithFewestReachable(int n, const vector<vector<int>>& shortestPathMatrix, int distanceThreshold) {
        int cityWithFewestReachable = -1;
        int fewestReachableCount = INT_MAX;

        // Count number of cities reachable within the distance threshold for each city
        for (int i = 0; i < n; i++) {
            int reachableCount = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && shortestPathMatrix[i][j] <= distanceThreshold) {
                    reachableCount++;
                }
            }

            if (reachableCount <= fewestReachableCount) {
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }
        return cityWithFewestReachable;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, vector<P>> adj;
        vector<vector<int>> shortestPathMatrix(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; i++) {
            shortestPathMatrix[i][i] = 0;  // Distance to itself is zero
        }

        for (const auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Compute shortest paths from each city using Dijkstra's algorithm
        for (int i = 0; i < n; i++) {
            dijkstra(n, adj, shortestPathMatrix[i], i);
        }

        return getCityWithFewestReachable(n, shortestPathMatrix, distanceThreshold);
    }
};
*/