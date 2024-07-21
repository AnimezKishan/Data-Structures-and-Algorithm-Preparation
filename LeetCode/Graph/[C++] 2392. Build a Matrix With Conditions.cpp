// Topological Sorting

class Solution {
public:
    void dfs(int node, unordered_map<int, vector<int>> &adj, vector<int> &visited, stack<int> &st, bool &hasCycle){
        visited[node] = 1; // mark node as visiting

        for(int &nbr : adj[node]){
            if(visited[nbr] == 0)
                dfs(nbr, adj, visited, st, hasCycle);
            else if(visited[nbr] == 1) {
                // cycle detected
                hasCycle = true;
                return;
            }
            else if(hasCycle)
                return;
        }    

        visited[node] = 2;
        st.push(node);    
    }
    vector<int> topoSort(vector<vector<int>> &edges, int k){
        unordered_map<int, vector<int>> adj;
        for(vector<int> &edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        /*
        0 -> not visited
        1 -> visiting (currently in stack while DFSing)
        2 -> visited
        */
        vector<int> visited(k+1, 0);
        stack<int> st;
        vector<int> order;
        bool hasCycle = false;

        for(int i=1; i<=k; i++){
            if(visited[i] == 0)
                dfs(i, adj, visited, st, hasCycle);
            
            if(hasCycle)
                return {};
        }

        while(!st.empty()){
            order.push_back(st.top());
            st.pop();
        }

        return order;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> topoRow = topoSort(rowConditions, k);
        vector<int> topoCol = topoSort(colConditions, k);
        
        // Either is empty, if any cycle was found.
        if(topoRow.empty() || topoCol.empty())
            return {};
        
        // assign position of element in matrix according to topologically sorted order of row and column.
        vector<vector<int>> matrix(k, vector<int>(k, 0)); 
        for(int i=0; i<k; i++){
            for(int j=0; j<k; j++){
                if(topoRow[i] == topoCol[j])
                    matrix[i][j] = topoRow[i];
            }
        }

        return matrix;
    }
};