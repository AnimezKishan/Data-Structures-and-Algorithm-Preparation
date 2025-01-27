// Topological Sort - Kahn's Algorithm 

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for(vector<int> &i : prerequisites) {
            int u = i[0];
            int v = i[1];

            adj[u].push_back(v);
            indegree[v]++;

        }

        queue<int> q;
        for(int i=0; i<numCourses; i++) 
            if(!indegree[i])
                q.push(i);

        unordered_map<int, unordered_set<int>> prerequisiteNodes;
        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(int &nbr : adj[u]) {
                prerequisiteNodes[nbr].insert(u);
                for(auto &node : prerequisiteNodes[u]){ // to establish prequisite between indirect connected nodes
                    prerequisiteNodes[nbr].insert(node);
                }

                indegree[nbr]--;
                if(indegree[nbr] == 0)
                    q.push(nbr);
            }
        }

        vector<bool> isReachable;
        for(vector<int> &query : queries) {
            int u = query[0];
            int v = query[1];

            isReachable.push_back(prerequisiteNodes[v].contains(u));
        }

        return isReachable;
    }
};