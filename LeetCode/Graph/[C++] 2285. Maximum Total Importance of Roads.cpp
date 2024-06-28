class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);

        for(int i=0; i<roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];

            degree[u]++;
            degree[v]++;
        }

        sort(begin(degree), end(degree));

        long long ans = 0;
        long long value = 1;

        for(int i=0; i<n; i++){
            ans += (value * degree[i]);
            value++;
        }

        return ans;
    }
};