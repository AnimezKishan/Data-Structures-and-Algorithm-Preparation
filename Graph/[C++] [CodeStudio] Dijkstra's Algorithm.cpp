//O(e*log(v) + e)

#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
    //adjcency list
    unordered_map<int, list<pair<int, int>>> adjList;
    for(int i=0;i<edges;i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int dist = vec[i][2];

        adjList[u].push_back({v, dist});
        adjList[v].push_back({u, dist});
    }

    //creation of distance array with infinite value initially.
    vector<int> ans(vertices);
    for(int i=0;i<vertices;i++)
        ans[i] = INT_MAX;
    
    //pair stores distance of node and the node itself
    set<pair<int, int>> s;
    ans[source] = 0;
    s.insert({0, source});

    while(!s.empty())
    {
        //first iterated value of set.
        auto top = *(s.begin());
        int nodeDistance = top.first;
        int node = top.second;

        s.erase(s.begin());

        for(auto i:adjList[node])
        {
            //if distance of current node plus distance of traversed node is less than value of distance array of traversed node.
            if(nodeDistance + i.second < ans[i.first])
            {
                //find if record exists
                auto record = s.find({ans[i.first], i.first});

                //if record exists in set, then erase it.
                if(record != s.end()){
                    s.erase(record);
                }

                //update distance
                ans[i.first] = nodeDistance + i.second;

                //insert in set
                s.insert({ans[i.first], i.first});
            }
        }

    }
    return ans;

}
