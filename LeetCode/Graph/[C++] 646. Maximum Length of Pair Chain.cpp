// For clear understanding, DRY RUN --> [[1,2],[7,8],[4,5]]

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        vector<int> indegree(n, 0);
        unordered_map<int, list<int>> adj;

        // Find number of possible pair-making in an Adjacency List
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(pairs[i][1] < pairs[j][0])
                {
                    adj[i].push_back(j);
                    indegree[j]++;
                }
            }
        }

        // Topological Sort using Kahn's Algorithm
        queue<int> q;
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }

        // Store distance for every node which could be covered using Topological Sort. 
        vector<int> distance(n, 0);
        while(!q.empty())
        {
            auto t = q.front();
            q.pop();

            for(auto nbr:adj[t])
            {
                indegree[nbr]--;
                distance[nbr] = max(distance[nbr], 1+distance[t]);
                if(indegree[nbr] == 0)
                    q.push(nbr);
            }
        }

        // It returns the maximum distance which can covered in a go, '+ 1' gives the total no. of pairs involved 
        return *max_element(distance.begin(), distance.end()) + 1;
    }
};