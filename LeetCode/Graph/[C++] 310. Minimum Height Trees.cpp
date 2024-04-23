// Topological Sort

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
            return {0};
        
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n);

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            indegree[u]++;
            indegree[v]++;

            adj[u].push_back(v);
            adj[v].push_back(u);
        } 

        // Push Leaf Nodes into queue
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 1)
                q.push(i);
        }

        // Start eliminating nodes starting from leaf node till you reach center with 1 or 2 nodes.
        while(n > 2){
            int size = q.size();
            n -= size;
            while(size--){
                int u = q.front();
                q.pop();

                for(int nbr:adj[u]){
                    indegree[nbr]--;
                    if(indegree[nbr] == 1)
                        q.push(nbr);
                }
            }
        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};