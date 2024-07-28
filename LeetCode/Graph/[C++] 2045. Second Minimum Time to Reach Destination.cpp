class Solution {
public:
    #define P pair<int, int>
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int, vector<int>> adj(n+1);
        for(vector<int> &edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        } 

        // to store shortest route
        vector<int> d1(n+1, INT_MAX);
        // to store second shortest route
        vector<int> d2(n+1, INT_MAX);
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 1});
        d1[1] = 0;

        while(!pq.empty()){
            auto [timePassed, node] = pq.top();
            pq.pop();

            // if second shortest distance got calculated
            if(node == n && d2[n] != INT_MAX)
                return d2[n];
            
            int interval = timePassed/change;
            // the current time is in red signal's interval
            if(interval % 2 == 1){
                // new time after waiting
                timePassed = change * (interval + 1);
            }

            // maintain shortest and second shortest distance using dijkstras
            for(auto &nbr : adj[node]){
                if(d1[nbr] > timePassed + time){
                    d2[nbr] = d1[nbr];
                    d1[nbr] = timePassed + time;
                    pq.push({timePassed + time, nbr});
                }
                else if(d2[nbr] > timePassed + time && d1[nbr] != timePassed + time){
                    d2[nbr] = timePassed + time;
                    pq.push({timePassed + time, nbr});
                }
            }
        }

        return -1;
    } 
};