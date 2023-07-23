#include <bits/stdc++.h>
using namespace std;
template <typename T>

class graph{
    public:
    unordered_map<T, list<T>> adj;
    
    /*
    direction = 0 -> undirected
    direction = 1 -> directed
    */
    void addEdge(T u, T v, bool direction)
    {
        adj[u].push_back(v);
        if(direction == 0)
            adj[v].push_back(u);
    }
    
    void printAdjList(){
        for(auto i:adj)
        {
            cout<<i.first<<" -> ";
            for(auto j:i.second)
            {
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    int n, m;
    graph<char> g;
    cout<<"Enter number of nodes: ";
    cin>>n;
    cout<<endl<<"Enter number of edges: ";
    cin>>m;
    for(int i=0;i<m;i++)
    {
        char u, v;
        cin>>u>>v;
        //For undirected graph
        g.addEdge(u, v, 0);
        
        //For directed graph
        //g.addEdge(u, v, 1);
    }
    cout<<endl<<endl;
    g.printAdjList();
    return 0;
}
