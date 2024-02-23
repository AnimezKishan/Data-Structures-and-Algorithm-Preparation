//Dijkstra's Algorithm using Min Heap

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, list<pair<int, int>>> adj;
        for(int i=0;i<flights.size();i++)
        {
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];

            adj[u].push_back({v, w});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > min_heap;

        min_heap.push({0, src, 0});

        //to avoid TLE
        vector<int> dist(n+1, INT_MAX);

        while(!min_heap.empty())
        {
            auto t = min_heap.top();
            min_heap.pop();
            int w = t[0];
            int node = t[1];
            int stop = t[2];

            //if destination reached
            if(node == dst)
                return w;
            
            //Optimization to avoid TLE
            if(dist[node]<stop) 
                continue;
            dist[node]=stop;
            
            //neglects paths which requires more than mentioned stops
            if(stop <= k)
            {
                for(auto i:adj[node])
                    min_heap.push({w+i.second, i.first, stop+1});
            }
        }
        return -1;
    }
};


// Without Min Heap
/*
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> distance(n, INT_MAX);
        unordered_map<int, vector<pair<int, int>>> adj;

        for(vector<int> &flight:flights){
            int u = flight[0];
            int v = flight[1];
            int w = flight[2];

            adj[u].push_back({v, w});
        }

        queue<pair<int, int>> q;
        q.push({src, 0});
        int steps = 0;

        while(!q.empty() && steps <= k){
            int size = q.size();
            while(size--){
                int u = q.front().first;
                int w = q.front().second;
                q.pop();

                for(auto i:adj[u]){
                    if(w+i.second < distance[i.first]){
                        distance[i.first] = w+i.second;
                        q.push({i.first, distance[i.first]});
                    }
                }

            }
            steps++;
        }

        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};
*/