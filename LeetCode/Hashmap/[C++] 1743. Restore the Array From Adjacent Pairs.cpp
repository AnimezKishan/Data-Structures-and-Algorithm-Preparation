//Hash Map + DFS

class Solution {
public:
    vector<int> ans;
    unordered_map<int, bool> visited;
    unordered_map<int, vector<int>> adj;

    void dfs(int u){
        visited[u] = true;
        ans.push_back(u);
        for(auto nbr:adj[u])
            if(!visited[nbr])
                dfs(nbr);
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        for(int i = 0;i<adjacentPairs.size();i++){
            int u = adjacentPairs[i][0];
            int v = adjacentPairs[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(auto i:adj)
        {
            // Find the first element of nums - it will only appear once in adjacentPairs.
            if(i.second.size() == 1)
            {
                dfs(i.first);
                break;
            }
        }
        
        return ans;
    }
};