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

bool bfs(int Node, unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, unordered_map<int, int> &parentNode){
    //make parent of starting node as -1
    parentNode[Node] = -1;
    visited[Node] = 1;
    queue<int> q;
    q.push(Node);

    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        for(auto i:adjList[frontNode])
        {
            //if the node was visited and it is not the parent of current node
            if(visited[i] && i != parentNode[frontNode])
                return 1;
            else if(!visited[i])
            {
                parentNode[i] = frontNode;
                visited[i] = 1;
                q.push(i);
            }
        }
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
        bool ans = bfs(i, adjList, visited, parentNode);
        if (ans == 1)
          return "Yes";
      }
    }
    
    return "No";
}
