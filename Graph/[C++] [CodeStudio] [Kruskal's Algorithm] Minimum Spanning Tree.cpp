/*
T.C -> O(n*log(n))
S.C -> O(n)
*/

#include<bits/stdc++.h>

bool cmp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

int findParent(vector<int> &parent, int node)
{
    if(parent[node] == node)
        return node;
    
    return parent[node] = findParent(parent, parent[node]); 
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u] < rank[v])
        parent[u] = v;
    
    else if(rank[v] < rank[u])
        parent[v] = u;
    else{
        parent[v] = u;
        rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    //sort it according to weight
    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n);
    //At start, make every node parent of it's own.
    for(int i=0;i<n;i++)
        parent[i] = i;
    
    vector<int> rank(n, 0);

    int ans = 0;

    for(int i=0;i<edges.size();i++)
    {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);

        if(u != v){
            ans += edges[i][2];
            unionSet(u, v, parent, rank);
        }
    }

    return ans;
}  