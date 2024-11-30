/*
In an Eulerian path of Directed Graph, starting node is whose outdegree[x] - indegree[x] == 1

Heirholzer's Algorithm
-> Build Adjacency List
-> Build Indegree and Outdegree
-> Find the startNode of EulerPath
*/
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        // Build Adj. List, Indegree and Outdegree
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> outdegree, indegree;

        for(int i=0; i<pairs.size(); i++) {
            int u = pairs[i][0];
            int v = pairs[i][1];

            adj[u].push_back(v);
            indegree[v]++;
            outdegree[u]++;
        }

        // starting node
        int startNode = pairs[0][0];
        for(auto &i : adj) {
            if(outdegree[i.first] - indegree[i.first] == 1){
                startNode = i.first;
                break;
            }
        }

        // DFS
        stack<int> st;
        st.push(startNode);
        vector<int> eulerPath;
        while(!st.empty()) {
            int node = st.top();
            
            if(!adj[node].empty()) {
                int nbr = adj[node].back();
                adj[node].pop_back();
                st.push(nbr);
            }
            else {
                eulerPath.push_back(node);
                st.pop();
            }
        }

        reverse(eulerPath.begin(), eulerPath.end());
        vector<vector<int>> ans;
        for(int i=0; i<eulerPath.size() - 1; i++) {
            ans.push_back({eulerPath[i], eulerPath[i+1]});
        }

        return ans;
    }
};