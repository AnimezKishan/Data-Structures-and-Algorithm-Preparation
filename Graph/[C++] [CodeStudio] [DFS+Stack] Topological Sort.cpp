//Use Case - If a directed graph has no topological sort present that means it is cyclic.

#include <bits/stdc++.h> 
void dfs(int Node, vector<bool> &visited, unordered_map<int, set<int>> &adjList, stack<int> &s)
{
    visited[Node] = 1;

    for(auto i:adjList[Node])
    {
        if(!visited[i])
        {
            dfs(i, visited, adjList, s);
        }
    }

    //Put the node in stack if no other element left after dfs recursive call.
    s.push(Node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<bool> visited(v);
    unordered_map<int, set<int>> adjList;
    stack<int> s;
    vector<int> ans;

    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].insert(v);
    }

    for(int i=0;i<v;i++)
    {
        if(!visited[i])
            dfs(i, visited, adjList, s);
    }

    //Nodes are stored in topologically sorted order.
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans; 
}