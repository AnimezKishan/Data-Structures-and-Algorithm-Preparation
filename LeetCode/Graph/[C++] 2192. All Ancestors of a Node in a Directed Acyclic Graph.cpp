class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int ancestor, unordered_map<int, vector<int>> &adj, int u){
        for(int &nbr : adj[u]){
            if(ans[nbr].empty() || ans[nbr].back() != ancestor) // to avoid duplicacy
            {
                ans[nbr].push_back(ancestor);
                dfs(ancestor, adj, nbr);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for(vector<int> &edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        } 

        // Take one node at a time and insert it for all child nodes as an ancestor.
        ans.resize(n);
        for(int i=0; i<n; i++){
            int ancestor = i;
            dfs(ancestor, adj, i);
        }

        return ans;
    }
};