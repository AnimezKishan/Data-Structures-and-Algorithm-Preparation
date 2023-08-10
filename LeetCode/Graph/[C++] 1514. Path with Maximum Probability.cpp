//Bellman Ford's Algorithm

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> ans(n);
        ans[start_node] = 1;

        for(int i=0;i<n-1;i++)
        {
            //To avoid TLE
            bool change_in_edge = false;
            
            for(int i=0;i<edges.size();i++)
            {
                int u = edges[i][0], v = edges[i][1];
                double w = succProb[i];

                if(ans[u] * w > ans[v])
                {
                    ans[v] = ans[u] * w;
                    change_in_edge = true;
                }
                    
                
                if(ans[v] * w > ans[u])
                {
                    ans[u] = ans[v] * w;
                    change_in_edge = true;
                }
            }

            //If no change is being made for value of node, no need for more traversal as maximum value is found.
            if(!change_in_edge)
                break;
        }

        return ans[end_node];
    }
};