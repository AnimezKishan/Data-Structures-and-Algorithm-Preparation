class Solution {
public:
    int N;
    typedef pair<int, int> P;
    int dijkstra(unordered_map<int, vector<P>> adj) {
        vector<int> distance(N, INT_MAX);
        priority_queue<P, vector<P>, greater<P>> pq; // min-heap
        pq.push({0, 0});
        distance[0] = 0;

        while(!pq.empty()) {
            int u = pq.top().second;
            int w = pq.top().first;
            pq.pop();

            for(auto &nbr : adj[u]) {
                int dist = nbr.second;
                int v = nbr.first;

                if(w + dist < distance[v]) {
                    distance[v] = w + dist;
                    pq.push({distance[v], v});
                }
            }
        }

        return distance[N-1];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        N = n;
        unordered_map<int, vector<P>> adj;

        for(int i=0; i<n-1; i++) {
            adj[i].push_back({i+1, 1});
        }

        vector<int> ans;
        for(vector<int> &query : queries) {
            int u = query[0];
            int v = query[1];

            adj[u].push_back({v, 1});

            int shortPath = dijkstra(adj);
            ans.push_back(shortPath);
        }

        return ans;
    }
};