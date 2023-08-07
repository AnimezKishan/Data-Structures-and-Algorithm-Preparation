//Pre-Requisite: Bridge in a Graph

class Solution {
public:
    void dfs(int Node, int parent, unordered_map<int, list<int>> &adj, vector<bool> &visited, vector<int> &discovery, vector<int> &low, int t, vector<vector<int>> &ans)
    {
        visited[Node] = 1;
        discovery[Node] = low[Node] = t++;

        for(auto i:adj[Node])
        {
            if(i == parent)
                continue;
            if(!visited[i])
            {
                dfs(i, Node, adj, visited, discovery, low, t, ans);
                low[Node] = min(low[Node], low[i]);

                if(low[i] > discovery[Node])
                {
                    vector<int> temp;
                    temp.push_back(Node);
                    temp.push_back(i);
                    ans.push_back(temp);
                }
            }
            else
            {
                //Back Edge
                low[Node] = min(low[Node], discovery[i]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& c) {
        unordered_map<int, list<int>> adj;
        vector<vector<int>> ans;
        for(int i=0;i<c.size();i++)
        {
            adj[c[i][0]].push_back(c[i][1]);
            adj[c[i][1]].push_back(c[i][0]);
        }

        int timer = 0;  
        vector<int> discovery(n, -1), low(n, -1);
        vector<bool> visited(n, false);

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
                dfs(i, -1, adj, visited, discovery, low, timer, ans);
        } 
        return ans;
    }
};