/*
1. Check Bipartite 
2. If yes, do BFS for each node to find maximum group no. possible for each node
3. Then, do DFS to find max group no. from each connected graph.
*/
class Solution {
public:
    bool isBipartite(int node, int currColor, unordered_map<int, vector<int>> &adj, vector<int> &colors) {
        colors[node] = currColor;

        for(int &nbr : adj[node]) {
            if(colors[nbr] == colors[node])
                return false;
            else if(colors[nbr] == -1) {
                if(!isBipartite(nbr, (currColor+1)%2, adj, colors))
                    return false;
            }
        }

        return true;
    }

    int bfs(int node, unordered_map<int, vector<int>> &adj, int n) {
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(node);
        visited[node] = true;

        int level = 1;
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                int curr = q.front();
                q.pop();

                for(int &nbr : adj[curr]) {
                    if(!visited[nbr]) {
                        visited[nbr] = true;
                        q.push(nbr);
                    }
                }
            }
            level++;
        }

        return level - 1;
    }

    int dfs(int node, unordered_map<int, vector<int>> &adj, vector<int> &levels, vector<bool> &visited) {
        visited[node] = true;

        int maxGroup = levels[node];
        for(int &nbr : adj[node]) {
            if(!visited[nbr]) {
                maxGroup = max(maxGroup, dfs(nbr, adj, levels, visited));
            }
        }

        return maxGroup;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for(vector<int> &edge : edges) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // check bipartite
        vector<int> colors(n, -1);
        for(int i=0; i<n; i++) {
            if(colors[i] == -1) {
                if(!isBipartite(i, 1, adj, colors))
                    return -1;
            }
        }

        // Do BFS for each node to find max level possible from each.
        vector<int> levels(n, 0);
        for(int i=0; i<n; i++) {
            levels[i] = bfs(i, adj, n);
        }

        // Now DFS to get maximum group no. from each connected graph
        vector<bool> visited(n, false);
        int maxGroups = 0;
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                maxGroups += dfs(i, adj, levels, visited);
            }
        }

        return maxGroups;
    }
};