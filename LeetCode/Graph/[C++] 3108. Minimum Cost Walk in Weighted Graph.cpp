// DSU

// ** When you do AND operation, the result will never increase. **
// So, take AND of all other nodes, before going to final node, this way you always get the minimum value
// ** AND of any number with -1 gives back the same number. **

class Solution {
    public:
        vector<int> parent;
        int find(int x) {
            if(parent[x] == x)
                return x;
            
            return parent[x] = find(parent[x]);
        }
    
        // simple union
        void Union(int x, int y) {
            parent[y] = x;
        }
        vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
            vector<int> cost(n);
            parent.resize(n);
    
            for(int i=0; i<n; i++) {
                parent[i] = i;
                cost[i] = -1;
            }
    
            for(vector<int> &edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int val = edge[2];
    
                int parent_u = find(u);
                int parent_v = find(v);
    
                if(parent_u != parent_v) {
                    cost[parent_u] &= cost[parent_v];
                    Union(parent_u, parent_v);
                }
    
                cost[parent_u] &= val;
            }
    
            vector<int> ans;
            for(vector<int> &q : query) {
                int u = q[0];
                int v = q[1];
    
                int p1 = find(u);
                int p2 = find(v);
    
                if(u == v)
                    ans.push_back(0);
                else if(p1 != p2)
                    ans.push_back(-1);
                else
                    ans.push_back(cost[p1]);
            }
    
            return ans;
        }
    };