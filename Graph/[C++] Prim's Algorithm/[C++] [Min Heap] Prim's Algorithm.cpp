//O(n*log(n))

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
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > min_heap;
    min_heap.push({0, 1});
    
    //algo
    while(min_heap.size())
    {
        int u = min_heap.top().second;
        int topW = min_heap.top().first; 
        min_heap.pop();

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
                min_heap.push({w, v});
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
