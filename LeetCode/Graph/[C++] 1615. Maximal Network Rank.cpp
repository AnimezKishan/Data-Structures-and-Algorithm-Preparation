class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> adj(n);
        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].insert(roads[i][1]);
            adj[roads[i][1]].insert(roads[i][0]);
        }

        int maxi = 0, count = 0;

        //check for every node
        for(int i=0;i<n;i++)
        {
            //check for adjacent nodes
            for(int j=i+1;j<n;j++)
            {
                //no. of roads connected to node
                count = adj[i].size();

                //no. of roads connected to other node
                count += adj[j].size();

                //If a road is directly connected to both cities, it is only counted once.
                if(adj[i].count(j))
                    count--;
                
                maxi = max(maxi, count);
            }
        }
        return maxi;
    }
};