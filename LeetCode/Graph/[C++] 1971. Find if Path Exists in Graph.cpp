// BFS

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination)
            return 1;

        unordered_map<int, vector<int>> adj;
        vector<bool> visited(n, false);

        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        q.push(source);
        visited[source] = 1;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            if(u == destination)
                return true;

            for(auto nbr : adj[u]){
                if(!visited[nbr]){
                    visited[nbr] = 1;
                    q.push(nbr);
                }
            }
        }

        return false;
    }
};