class Graph {
public:
    int N;
    unordered_map<int, vector<pair<int, int>>> adj;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

    Graph(int n, vector<vector<int>>& edges) {
        N = n;
        for(auto &edge:edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
        }
    }
    
    void addEdge(vector<int> edge) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        adj[u].push_back({v, w});
    }
    
    // Dijkstra's Algo (Priority Queue)
    int shortestPath(int node1, int node2) {
        vector<int> distance(N, INT_MAX);

        distance[node1] = 0;
        min_heap.push({0, node1});

        while(!min_heap.empty()){
            auto t = min_heap.top();
            int currW = t.first;
            int u = t.second;
            min_heap.pop();

            for(auto &nbr:adj[u]){
                int v = nbr.first;
                int dist = nbr.second;

                if(currW + dist < distance[v]){
                    distance[v] = currW + dist;
                    min_heap.push({currW + dist, v});
                }
            }
        } 
        return (distance[node2] == INT_MAX ? -1 : distance[node2]);
    }
};
