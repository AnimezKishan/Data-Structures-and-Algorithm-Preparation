// Topological Sort (Kahn's Algorithm)

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& p) {
        vector<int> indegree(numCourses);
        unordered_map<int, list<int>> adj;

        for(int i=0;i<p.size();i++)
        {
            adj[p[i][1]].push_back(p[i][0]);
            indegree[p[i][0]]++;
        }

        vector<int> ans;

        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty())
        {
            auto t = q.front();
            q.pop();

            ans.push_back(t);

            for(auto nbr:adj[t])
            {
                indegree[nbr]--;
                if(indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        if(ans.size() == numCourses)
            return ans;
        else
            return {};
    }
};