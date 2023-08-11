/*Bipartite Graph can be said as:-
A node could be assigned color either red(0) or blue(1).
So, if a node is assigned red, so it's neighbouring node should be of different color i.e. blue. 
*/

class Solution {
public:
    bool dfs(int node, vector<vector<int>> &graph, vector<int> &visited, int color)
    {
        visited[node] = color;
        for(auto nbr:graph[node])
        {
            if(visited[nbr] == -1)
            {
                bool isFalse = dfs(nbr, graph, visited, (color+1)%2);
                if(!isFalse)
                    return false;
            }
            //if the neighbour node is visited, then the visited neighbour should have a different color.
            else if(visited[nbr] == color){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(), color=0;
        vector<int> visited(n, -1);

        for(int i=0;i<n;i++)
        {
            if(visited[i] == -1)
            {
                //(color+1)%2 means color can either be 0 or 1.
                bool isFalse = dfs(i, graph, visited, (color+1)%2);
                if(!isFalse)
                    return false;
            }
        }
        return true;
    }
};