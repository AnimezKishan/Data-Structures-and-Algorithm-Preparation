class Solution {
public:
    bool dfs(int node, unordered_map<int, vector<int>> &adj, int dest, unordered_map<int, bool> &visited) {
        visited[node] = true;

        if(node == dest)
            return true;

        for(auto &nbr : adj[node]) {
            if(!visited[nbr]){
                bool isReachable = dfs(nbr, adj, dest, visited);
                if(isReachable)
                    return true;
            }
        }

        return false;
    } 
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for(vector<int> &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            unordered_map<int, bool> visited;

            // if we can already reach from one node to another, adding current edge will form a cycle
            if(dfs(u, adj, v, visited))
                return edge;
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        } 

        return {};
    }
};