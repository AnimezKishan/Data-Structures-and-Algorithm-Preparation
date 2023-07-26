/*
-> In DFSvisited, we mark it visited until it's resurcive call exists
-> So, a node contributes to a cyclic graph if it is visited and has it's DFSvisited marked true within the resursive call
*/

/*
T.C -> O(n+e)
S.C -> O(n)
*/
#include<bits/stdc++.h>
bool dfs(int Node, unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &DFSvisited, unordered_map<int, bool> &visited){
  
  visited[Node] = 1;
  DFSvisited[Node] = 1;
  
  for(auto i:adjList[Node])
  {
    if(!visited[i])
    {
      bool temp = dfs(i, adjList, DFSvisited, visited);
      if(temp)
        return 1;
    }
    else if(DFSvisited[i])
      return 1;
  }

  //backtracking
  DFSvisited[Node] = 0;
  return 0;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int, set<int>> adjList;
  unordered_map<int, bool> visited;
  unordered_map<int, bool> DFSvisited;
  
  //make an adjcency list
  for(int i=0;i<edges.size();i++)
  {
    int u = edges[i].first;
    int v = edges[i].second;

    adjList[u].insert(v);
  } 

  for(int i=1;i<=n;i++)
  {
    if(!visited[i])
    {
      bool ans = dfs(i, adjList, DFSvisited, visited);
      if(ans)
        return 1;
    }
  }
  return 0;
}