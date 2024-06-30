// DSU 
/*
Why DSU?
In Brute Force, you need to remove each edge and check if graph is fully traversable or not each time.

In DSU, firstly all nodes are independent and disconnected. We start connecting edge on each iteration until it's fully traversable. (until there's only one component in graph)
*/


class DSU {
    public: 
        vector<int> parent;
        vector<int> rank;
        int components;
        
        DSU(int n) {
            parent.resize(n+1);
            rank.resize(n+1);
            components = n;
            for(int i = 1; i<=n; i++) {
                parent[i] = i;
            }
        }
    
        int find (int x) {
            if (x == parent[x]) 
                return x;

            return parent[x] = find(parent[x]);
        }

        void Union (int x, int y) {
            int x_parent = find(x);
            int y_parent = find(y);

            if (x_parent == y_parent) 
                return;

            if(rank[x_parent] > rank[y_parent]) {
                parent[y_parent] = x_parent;
            } else if(rank[x_parent] < rank[y_parent]) {
                parent[x_parent] = y_parent;
            } else {
                parent[x_parent] = y_parent;
                rank[y_parent]++;
            }
            components--;
        }
    
        bool isSingle() {
            return components == 1;
        }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU Alice(n);
        DSU Bob(n);

        auto lambda = [&](vector<int> &vec1, vector<int> &vec2){
            return vec1[0] > vec2[0];
        };

        // Sort it so that we can firstly deal with Type 3 edges.
        sort(begin(edges), end(edges), lambda);

        int edgeCount = 0;
        for(vector<int> &edge : edges){
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];

            if(type == 3){
                bool edgeAdded = false;

                // If not connected (both with different parents), then connect them.
                // Alice
                if(Alice.find(u) != Alice.find(v)){
                    edgeAdded = true;
                    Alice.Union(u, v);
                }

                // Bob
                if(Bob.find(u) != Bob.find(v)){
                    edgeAdded = true;
                    Bob.Union(u, v);
                }

                if(edgeAdded)
                    edgeCount++;
            }
            else if(type == 2){
                bool edgeAdded = false;
                // Bob
                if(Bob.find(u) != Bob.find(v)){
                    edgeAdded = true;
                    Bob.Union(u, v);
                }

                if(edgeAdded)
                    edgeCount++;
            }
            else {
                bool edgeAdded = false;
                // Alice
                if(Alice.find(u) != Alice.find(v)){
                    edgeAdded = true;
                    Alice.Union(u, v);
                }

                if(edgeAdded)
                    edgeCount++;
            }
        }

        if(Alice.isSingle() && Bob.isSingle())
            // Return the extra no. of edges
            return edges.size() - edgeCount;
        
        return -1;
    }
};