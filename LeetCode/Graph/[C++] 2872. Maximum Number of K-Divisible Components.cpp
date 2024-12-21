class Solution {
public:
    long long dfs(int root, unordered_map<int, vector<int>> &adj, vector<bool> &visited, vector<long long> &values, int &k, int &ans) {
        visited[root] = true;

        for (int &nbr : adj[root]) {
            if (!visited[nbr]) {
                long long val = dfs(nbr, adj, visited, values, k, ans);
                values[root] += val;
            }
        }

        if (values[root] % k == 0) {
            ans++;
            return 0;
        } else {
            return values[root];
        }
    }

    int maxKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k) {
        unordered_map<int, vector<int>> adj;

        for (vector<int> &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;
        vector<long long> val(values.begin(), values.end());
        vector<bool> visited(n, false);
        dfs(0, adj, visited, val, k, ans);

        return ans == 0 ? 1 : ans;
    }
};
