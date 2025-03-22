// If a graph component is complete then it's v*(v-1) = e, where v = vertices in the component and e = total nodes from each vertex of component

class Solution {
    public:
        void dfs(int node, unordered_map<int, vector<int>> &adj, vector<bool> &visited, int &v, int &e) {
            visited[node] = true;
            v++;
            e += adj[node].size();
    
            for(int &nbr : adj[node]) {
                if(!visited[nbr])
                    dfs(nbr, adj, visited, v, e);
            }
        }
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            unordered_map<int, vector<int>> adj;
    
            for(vector<int> &edge : edges){
                int u = edge[0];
                int v = edge[1];
    
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
    
            int ans = 0;
            vector<bool> visited(n, false);
            for(int i=0; i<n; i++) {
                if(!visited[i]) {
                    int v = 0;
                    int e = 0;
    
                    dfs(i, adj, visited, v, e);
    
                    if(v*(v-1) == e)
                        ans++;
                }
            }
    
            return ans;
        }
    };