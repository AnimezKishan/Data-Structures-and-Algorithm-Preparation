//O(n^2)

#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int>>> adjList;

    //Adjacency List
    for(int i=0;i<m;i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int weight = g[i].second;

        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }

    //to store the minimum distance between nodes.
    vector<int> key(n+1, INT_MAX);

    //to check if a node is present in mst or not.
    vector<bool> mst(n+1, false);

    //to store parent of a node.
    vector<int> parent(n+1, -1);

    key[1] = 0;
    
    //algo
    for(int i=0;i<=n;i++)
    {
        int mini = INT_MAX;
        int u;

        //finds the min node which is currently not present in mst.
        for(int j=0;j<=n;j++)
        {
            if(mst[j] == false && key[j] < mini)
            {
                mini = key[j];
                u = j;
            }
        }

        //mark min node true
        mst[u] = true;

        //check it's adjacent node
        for(auto adj:adjList[u])
        {
            int v = adj.first;
            int w = adj.second;
            if(mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> ans;
    for(int i=2;i<=n;i++)
    {
        ans.push_back({{parent[i], i}, key[i]});
    }
    return ans;
}
