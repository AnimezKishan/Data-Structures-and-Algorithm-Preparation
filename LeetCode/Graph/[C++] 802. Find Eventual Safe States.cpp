class Solution {
public:
    bool isCycle(int u, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &inRecursion) {
        visited[u] = true;
        inRecursion[u] = true;

        for(int &v : adj[u]) {
            if(visited[v] == false && isCycle(v, adj, visited, inRecursion)) // if not visited, check if it's forming cycle
                return true;
            else if(inRecursion[v]) // linked to a cycle forming node
                return true;
        }

        inRecursion[u] = false; // using backtracking, make all linked node false if they doesn't form a cycle.
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false), inRecursion(n, false);
        
        // mark all the nodes which leads into forming a circle.
        for(int i=0; i<n; i++) {
            if(!visited[i])
                isCycle(i, graph, visited, inRecursion);
        }

        vector<int> safeNodes;
        for(int i=0; i<n; i++) {
            if(inRecursion[i] == false)
                safeNodes.push_back(i);
        }
        return safeNodes;
    }
};