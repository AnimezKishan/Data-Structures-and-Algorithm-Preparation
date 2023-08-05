/*
Algo- 
-> Sort all nodes basis on their finishing time (Topological Sort) 
-> Transpose the graph (change direction)
-> Using DFS on Topological Sort, count/print Strongly Connected Components (SCC)
*/

#include<bits/stdc++.h>
void dfs(int Node, vector<bool> &visited, unordered_map<int, list<int>> &adj, stack<int> &s)
{
    visited[Node] = true;

    for(auto i:adj[Node])
    {
        if(!visited[i])
        {
            dfs(i, visited, adj, s);            
        }
    }
    s.push(Node);
}

void dfs2(int Node, vector<bool> &visited, unordered_map<int, list<int>> &transpose)
{
    visited[Node] = true;

    for(auto i:transpose[Node])
    {
        if(!visited[i])
            dfs2(i, visited, transpose);
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    //Adjacency List
	unordered_map<int, list<int>> adj;
    for(int i=0;i<edges.size();i++)
        adj[edges[i][0]].push_back(edges[i][1]);

    //Step 1    
    //Topological Sort
    stack<int> s;
    vector<bool> visited(v, false);

    for(int i=0;i<v;i++)
    {
        if(!visited[i])
            dfs(i, visited, adj, s);
    }

    //Step 2
    //create a transpose graph
    unordered_map<int, list<int>> transpose;
    for(int i=0;i<edges.size();i++)
        transpose[edges[i][1]].push_back(edges[i][0]);

    //Step 3
    for(int i=0;i<v;i++)
        visited[i] = false;
    
    int count = 0;
    while(!s.empty())
    {
        int top = s.top();
        s.pop();

        if(!visited[top])
        {
            count++;
            dfs2(top, visited, transpose);
        }
    }
    return count;

}