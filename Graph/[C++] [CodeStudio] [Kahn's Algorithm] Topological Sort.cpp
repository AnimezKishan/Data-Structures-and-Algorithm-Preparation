// O(v+e)

#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>> adjList;
    vector<int> ans;
    
    for(int i=0;i<edges.size();i++)
        adjList[edges[i][0]].push_back(edges[i][1]);
    
    //find all indegrees
    vector<int> indegree(v);
    for(auto i:adjList)
    {
        for(auto j:i.second)
            indegree[j]++;
    }
    
    //push node with 0 indegree
    queue<int> q;
    for(int i=0;i<v;i++)
        if(indegree[i] == 0)
            q.push(i);
    
    //bfs
    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        
        ans.push_back(frontNode);
        for(auto i:adjList[frontNode])
        {
            indegree[i]--;
            if(indegree[i] == 0)
                q.push(i);
        }
    }
    
    return ans;
}