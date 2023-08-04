#include<bits/stdc++.h>
void dfs(int Node, unordered_map<int, list<int>> &adjList, int parent, int t, vector<int> &discovery, 
         vector<int> &low, vector<vector<int>> &ans, vector<bool> &visited)
{
    visited[Node] = 1;
    discovery[Node] = low[Node] = t++;

    for(auto i:adjList[Node])
    {
        if(i == parent)
            continue;
        if(!visited[i])
        {
            dfs(i, adjList, Node, t, discovery, low, ans, visited);
            //if a back edge is their in it's child, child's low value will be small than node.
            low[Node] = min(low[Node], low[i]);
            
            //check if edge is bridge
            if(low[i] > discovery[Node])
            {
                vector<int> temp;
                temp.push_back(Node);
                temp.push_back(i);
                ans.push_back(temp);
            } 
        }
        else{
            //node already visited and also not a parent node
            //back edge
            low[Node] = min(low[Node], discovery[i]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int, list<int>> adjList;
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int timer = 0;
    vector<int> discovery(v, -1), low(v, -1);
    int parent = -1;
    vector<bool> visited(v, false);
    vector<vector<int>> ans;

    //dfs
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            dfs(i, adjList, parent, timer, discovery, low, ans, visited);
        }
    }
    return ans;
}