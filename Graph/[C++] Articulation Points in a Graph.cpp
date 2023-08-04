// Pre-Requisite --> Bridge in a Graph

/*
Graph used in program -->
    0 -- 3
    | ⤡  |
    |  ⤡ |
    1    4
    |
    |
    2
    
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int Node, int parent, unordered_map<int, list<int>> &adj, vector<int> &discovery, vector<int> &low, vector<bool> &visited, vector<int> &ans, int t){
    int child = 0;
    visited[Node] = 1;
    discovery[Node] = low[Node] = t++;
    
    for(auto i:adj[Node])
    {
        if(i == parent)
            continue;
        
        if(!visited[i])
        {
            dfs(i, Node, adj, discovery, low, visited, ans, t);
            low[Node] = min(low[Node], low[i]);
            
            //For Articulation Point, the node doesn't have any back egde and shouldn't be the starting node
            if(low[i] >= discovery[Node] && parent != -1)
                ans[Node] = 1;
            
            child++;
        }
        else{
            //back edge
            low[Node] = min(low[Node], discovery[i]);
        }
    }
    
    //Edge Case - If the starting node is a Articulation Point
    if(parent == -1 && child > 1)
        ans[Node] = 1;
} 

int main()
{
    int v = 5;
    vector<pair<int, int>> edges = {{0, 3}, {3, 4}, {4, 0}, {0, 1}, {1, 2}};
    
    unordered_map<int, list<int>> adj;
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int timer = 0;
    int parent = -1;
    vector<int> discovery(v, -1), low(v, -1);
    vector<bool> visited(v);
    vector<int> ans(v, 0);
    
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
            dfs(i, parent, adj, discovery, low, visited, ans, timer);
    }
    
    cout<<"Articulation Points/Cut Vertices are: "<<endl;
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i] != 0)
            cout<<i<<" ";
    }
    return 0;
}
