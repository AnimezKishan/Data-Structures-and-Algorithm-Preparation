// O(n+e) [n = no. of vertices, e = no. of edges]

#include <bits/stdc++.h> 
void makeAdjList(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> &edges)
{
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int>> &adjList, vector<int> &ans, unordered_map<int, bool> &visited, int index)
{
    queue<int> q;
    q.push(index);
    visited[index] = 1;

    while(!q.empty())
    {
        //store the current node.
        int Node = q.front();
        q.pop();

        ans.push_back(Node);

        //enque the connected node if it is not visited. 
        for(auto i:adjList[Node])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int> ans;
    unordered_map<int, bool> visited;

    //Set is used to store nodes in sorted order.
    unordered_map<int, set<int>> adjList;

    //Make an Adjcency List out of given edges
    makeAdjList(adjList, edges);

    //Traverse for all vertices as it could be a disconnected graph.
    for(int i=0;i<vertex;i++)
    {
        if(!visited[i])
            bfs(adjList, ans, visited, i);
    }
    return ans;
}