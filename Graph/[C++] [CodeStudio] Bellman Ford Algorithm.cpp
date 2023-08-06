/*
Dijkstra's Algorithm gives wrong answer when it has to deal with negative weight.
Here, Bellman Ford's Algorithm comes in handy.   

It's also used to find if there is a negative cycle in the graph or not.

Algo-
-> Apply (n-1) times this
    if distance[u] + w < distance[v]
        update distance[v] = distance[u] + w

-> Apply the above condition one more time and if the shortest distance gets updated, 
   it means it has a negative cycle and shortest path cannot be found. 
*/

#include <bits/stdc++.h>
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {

    vector<int> distance(n+1, 1e9);
    distance[src] = 0;

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m;j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];

            if(distance[u] != 1e9 && ((distance[u] + weight) < distance[v]))
                distance[v] = distance[u] + weight;
        }
    }

    //Here, not checking for one more time, as it's mentioned graph doesn't contain any negative cycle.
    return distance[dest];

    /*
    To check for negative cycle
    bool flag = 0;
    for(int j=0;j<m;j++)
    {
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];

            if(distance[u] != 1e9 && ((distance[u] + weight) < distance[v]))
            {
                flag = 1;
                break;
            }
    }

    if(flag == 1)
    {
        cout<<"Negative Cycle Exists!!";
        return -1;
    }
    */
}