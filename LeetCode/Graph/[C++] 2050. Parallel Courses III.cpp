// Topological Sort + vector to store duration and return element with maximum duration [kind of Dijkstra's/Bellman Ford Algo].

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int, vector<int>> adjList;
        vector<int> indegree(n);

        for(int i=0;i<relations.size();i++){
            int u = relations[i][0] - 1;
            int v = relations[i][1] - 1;

            adjList[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        vector<int> duration(n, 0);
        for(int i=0;i<indegree.size();i++){
            if(indegree[i] == 0)
            { 
                q.push(i);
                duration[i] = time[i];
            }
        }

        while(!q.empty()){
            auto t = q.front();
            q.pop();

            for(auto nbr:adjList[t]){
                indegree[nbr]--;
                if(duration[nbr] < time[nbr] + duration[t])
                    duration[nbr] = time[nbr] + duration[t];
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        
        return *max_element(begin(duration), end(duration));

    }
};