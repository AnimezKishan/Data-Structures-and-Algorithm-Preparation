/*
Dijkstra's Algo without considering -ve edges
    -> if shortest path < target then return {}
    -> if shortest path == target then return edges.
    -> if shortest path > target then try finding path using -ve edges.
        -> as soon as shortest path <= target then make last -ve edge += (target - shortest path) 
        -> also when shortest path is found, mark all other negative path as any +ve weight
*/
class Solution {
public:
    typedef pair<long, long> P;
    typedef long long ll;
    int MAX = 2e9;

    ll dijkstraAlgo(vector<vector<int>>& edges, int n, int src, int dest) {
        unordered_map<int, vector<P>> adj;
        for(vector<int> &edge : edges){
            if(edge[2] != -1){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];

                adj[u].push_back({v, w});
                adj[v].push_back({u, w});
            }
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<bool> visited(n, false);
        vector<ll> distance(n, INT_MAX);

        pq.push({0, src});
        distance[src] = 0;

        while(!pq.empty()){
            ll currNode = pq.top().second;
            ll currW = pq.top().first;
            pq.pop();

            if(visited[currNode])
                continue;
            
            visited[currNode] = true;

            for(auto &[nbr, w] : adj[currNode]){
                if(distance[nbr] > currW + w){
                    distance[nbr] = currW + w;
                    pq.push({distance[nbr], nbr});
                }
            }
        }

        return distance[dest];
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        ll shortestDistance = dijkstraAlgo(edges, n, source, destination);

        if(shortestDistance < target)
            return {};

        bool matchedTarget = (shortestDistance == target);

        for(vector<int> &edge : edges) {
            if(edge[2] == -1){
                edge[2] = (matchedTarget == true) ? MAX : 1;

                if(!matchedTarget){
                    ll newShortestDistance = dijkstraAlgo(edges, n, source, destination);

                    if(newShortestDistance <= target){
                        matchedTarget = true;
                        edge[2] += (target - newShortestDistance);
                    }
                }
            }
        }

        if(!matchedTarget)
            return {};

        return edges;
    }
};