class Solution {
public:
    vector<vector<int>> buildList(const vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size() + 1);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return adj;
    }

    void dfsColor(const vector<vector<int>>& adj, int u, int parent,
                  vector<int>& color, int& evenCnt, int& oddCnt) {
        if (color[u] == 0) 
            evenCnt++;
        else 
            oddCnt++;

        for (int v : adj[u]) if (v != parent) {
            color[v] = color[u] ^ 1;
            dfsColor(adj, v, u, color, evenCnt, oddCnt);
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        auto adjA = buildList(edges1), adjB = buildList(edges2);
        int n = adjA.size(), m = adjB.size();
        vector<int> colorA(n, -1), colorB(m, -1);
        int evenA = 0, oddA = 0, evenB = 0, oddB = 0;

        colorA[0] = 0;
        dfsColor(adjA, 0, -1, colorA, evenA, oddA);
        colorB[0] = 0;
        dfsColor(adjB, 0, -1, colorB, evenB, oddB);
        int maxiB = max(evenB, oddB);
        vector<int> res(n);
        for (int i = 0; i < n; i++)
            res[i] = (colorA[i] == 0 ? evenA : oddA) + maxiB;
            
        return res;
    }
};