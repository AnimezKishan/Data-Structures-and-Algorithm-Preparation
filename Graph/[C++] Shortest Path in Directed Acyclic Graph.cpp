// O(n+e)

#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
    unordered_map<int, list<pair<int, int>>> adj;
    
    void addEdge(int u, int v, int weight) {
        pair<int, int> p = make_pair(v, weight);
        adj[u].push_back(p);
    }
    
    void printAdj(){
        for(auto i:adj)
        {
            cout<<i.first<<" -> ";
            for(auto j:i.second)
            {
                cout<<"("<<j.first<<" , "<<j.second<<"), ";
            }
            cout<<endl;
        }
    }
    
    void dfs(int Node, unordered_map<int, bool> &visited, stack<int> &topo)
    {
        visited[Node] = 1;
        
        for(auto i:adj[Node])
        {
            if(!visited[i.first])
                dfs(i.first, visited, topo);
        }
        topo.push(Node);
    }
    
    void getShortestPath(int src, vector<int> &dist, stack<int> &s)
    {
        //set distance from source to source as 0
        dist[src] = 0;
    
        while(!s.empty())
        {
            int temp = s.top();
            s.pop();
            
            if(dist[temp] != INT_MAX)
            {
                for(auto i:adj[temp])
                    if(dist[temp] + i.second < dist[i.first])
                        dist[i.first] = dist[temp] + i.second;
            }
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    
    g.printAdj();
    
    //topoplogical sort.
    int n = 6;
    unordered_map<int, bool> visited;
    stack<int> s;
    
    //here, stack stores the topological sort.
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
            g.dfs(i, visited, s);
    }
    
    int src = 1;
    vector<int> dist(n);
    for(int i=0;i<n;i++)
        dist[i] = INT_MAX;
    
    g.getShortestPath(src, dist, s);
    
    cout<<endl<<"Distance of all node from source i.e. "<<src<<" is :"<<endl;
    for(auto i:dist)
        cout<<i<<" ";
    return 0;
}
