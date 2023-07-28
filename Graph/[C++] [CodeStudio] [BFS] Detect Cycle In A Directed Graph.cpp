#include<bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  
  //Adjcency List
  unordered_map<int, list<int>> adjList;
  for(int i=0;i<edges.size();i++)
    adjList[edges[i].first-1].push_back(edges[i].second-1);
  
  //find all indegree
  vector<int> indegree(n);
  for(auto i:adjList)
    for(auto j:i.second)
      indegree[j]++;
  
  int cnt = 0;
  queue<int> q;
  for(int i=0;i<n;i++)
    if(indegree[i] == 0)
      q.push(i);  
  
  //bfs
  while(!q.empty())
  {
    int frontNode = q.front();
    q.pop();
    
    cnt++;
    for(auto i:adjList[frontNode])
    {
      indegree[i]--;
      if(indegree[i] == 0)
        q.push(i);
    }
  }
  
  /*
  If it is a directed acyclic graph, all nodes of graph can be fully traversed using topological sort.
  If any cycle is present, it is not possible to traverse the graph fully.
  */
  if(cnt == n)
    return false;
  else  
    return true;
  
}