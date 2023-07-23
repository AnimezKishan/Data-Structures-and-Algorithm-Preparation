/*
Time Complexity
O(N + M), where N and M denote the number of nodes and the number of edges in the graph, respectively.
We are traversing each node and each edge of the graph, so the overall time complexity is O(N + M).


Space Complexity
O(N + M), where N and M denote the number of nodes and the number of edges in the graph, respectively.
The graph array and the adjacencyList array both contain a total of N nodes and M edge. So, the overall space complexity is O(N + M).
*/

#include <bits/stdc++.h> 
vector <vector<int>> printAdjacency(int n, int m, vector <vector<int>> &edges) {

    //this will store all adjacent nodes corresponding on indexes.
    vector<int> neighbour[n];
    for(int i=0;i<m;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        //undirected graph
        neighbour[u].push_back(v);
        neighbour[v].push_back(u);
    }

    vector<vector<int>> ans(n);
    for(int i=0;i<n;i++)
    {
        //Push the node
        ans[i].push_back(i);
        for(int j=0;j<neighbour[i].size();j++)
        {
            //Push Neighbouring nodes of that node
            ans[i].push_back(neighbour[i][j]);
        }
    }
    return ans;

}