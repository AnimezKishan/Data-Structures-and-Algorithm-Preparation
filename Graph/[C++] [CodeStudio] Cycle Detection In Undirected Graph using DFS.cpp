#include<bits/stdc++.h>
void makeadjList(vector<vector<int>> &edges, unordered_map<int, set<int>> &adjList)
{
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].insert(v);
        adjList[v].insert(u); 
    }
}

bool dfs(int Node, unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, int parent){
    visited[Node] = 1;
    for(auto i:adjList[Node])
    {
        if(!visited[i])
        {
            bool cycleDetected = dfs(i, adjList, visited, Node);
            if(cycleDetected == 1)
                return 1;
        }
        else if(i != parent)
            return 1;
    }
    return 0;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int, int> parentNode;
    unordered_map<int, bool> visited;
    unordered_map<int, set<int>> adjList;

    makeadjList(edges, adjList);

    for(int i=0;i<n;i++)
    {
      if(!visited[i]) {
        bool ans = dfs(i, adjList, visited, -1);
        if (ans == 1)
          return "Yes";
      }
    }
    
    return "No";
}
