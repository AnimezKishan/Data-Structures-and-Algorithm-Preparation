//Dijkstra's Algorithm

class Solution {
public:
    void dijkstra(char &source, unordered_map<char, vector<pair<char, int>>> &adj, vector<vector<long long>> &costMatrix) {

        //min-heap
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;

        pq.push({0, source});

        while(!pq.empty()) {
            int w = pq.top().first;
            char adjNode = pq.top().second;
            pq.pop();

            for(auto &it : adj[adjNode]) {
                char adjNode = it.first;
                int currW = it.second;

                if(costMatrix[source - 'a'][adjNode - 'a'] > w + currW) {
                    costMatrix[source - 'a'][adjNode - 'a'] = w + currW;
                    pq.push({w + currW, adjNode});
                }
            }

        }
        return;
    }

    //V = no of vertices
    //E = no of edges
    //O(n * (V+E)log(V))
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char, vector<pair<char, int>>> adj;

        for(int i = 0; i < original.size(); i++) {
            adj[original[i]].push_back({changed[i], cost[i]});
        }

        vector<vector<long long>> costMatrix(26, vector<long long>(26, INT_MAX));

        //Populate the costMatrix using Dijkstra's Algorithm
        for(int i = 0; i < source.length(); i++) { 
            char ch = source[i];
            dijkstra(ch, adj, costMatrix);
        }

        long long ans = 0;

        for(int i = 0; i < source.length(); i++) {
            if(source[i] == target[i]) {
                continue;
            }

            if(costMatrix[source[i] - 'a'][target[i] - 'a'] == INT_MAX) {
                return -1;
            }

            ans += costMatrix[source[i] - 'a'][target[i] - 'a'];

        }

        return ans;
    }
};