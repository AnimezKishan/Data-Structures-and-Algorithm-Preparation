void makeAdjList(vector<vector<int>> &edges, unordered_map<int, set<int>> &adjList)
{
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void dfs(int Node, unordered_map<int, set<int>> &adjList, vector<int> &temp, unordered_map<int, bool> &visited)
{
    //stroe the current node and make it visited.
    temp.push_back(Node);
    visited[Node] = 1;

    //recursive call for every connected node.
    for(auto i:adjList[Node])
    {
        if(!visited[i])
            dfs(i, adjList, temp, visited);
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, bool> visited;
    unordered_map<int, set<int>> adjList;
    vector<int> temp;
    vector<vector<int>> ans;

    //make adjcency list.
    makeAdjList(edges, adjList);

    //for all node, call dfs, if the node is not visited.
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            vector<int> temp;
            dfs(i, adjList, temp, visited);
            ans.push_back(temp);
        }
    }
    return ans;
}