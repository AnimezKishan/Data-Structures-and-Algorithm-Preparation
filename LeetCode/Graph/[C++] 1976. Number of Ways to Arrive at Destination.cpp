class Solution {
    public:
        typedef pair<long long, int> P;
        int MOD = 1e9 + 7;
        int countPaths(int n, vector<vector<int>>& roads) {
            unordered_map<int, vector<pair<int, int>>> adj;
    
            for(vector<int> &road : roads) {
                int u = road[0];
                int v = road[1];
                int w = road[2];
    
                adj[u].push_back({v, w});
                adj[v].push_back({u, w});
            }
    
    
            vector<long long> distance(n, LLONG_MAX);
            distance[0] = 0;
            vector<long long> ways(n, 0);
            ways[0] = 1;
            priority_queue<P, vector<P>, greater<P>> pq; // min-heap
            pq.push({0, 0});
    
            while(!pq.empty()) {
                long long w = pq.top().first;
                int u = pq.top().second;
                pq.pop();
    
                if(w > distance[u])
                    continue;
    
                for(auto &x : adj[u]) {
                    int v = x.first;
                    int currW = x.second;
                    
                    long long newDist = w + currW;
                    if(newDist < distance[v]) {
                        distance[v] = newDist;
                        ways[v] = ways[u];
                        pq.push({newDist, v});
                    } else if(newDist == distance[v]) {
                        ways[v] = (ways[v] + ways[u]) % MOD;
                    }
                }
            }
    
            return ways[n-1] % MOD;
        }
    };