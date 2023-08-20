//Reference - https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/solutions/402945/c-with-picture-generic-topological-sort/

class Solution {
public:
    void dfs(int curr, int n, vector<vector<int>> &adj, vector<int> &indegree, vector<int> &ans)
    {
        if(curr < n)
            ans.push_back(curr);
        
        //mark visisted
        indegree[curr] = -1;

        for(auto next:adj[curr])
        {
            indegree[next]--;
            if(indegree[next] == 0)
                dfs(next, n, adj, indegree, ans);
        }
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<vector<int>> adj(n+m);
        vector<int> indegree(n+m, 0);

        //bound with extra node for group dependency
        for(int i=0;i<group.size();i++)
        {
            //no group
            if(group[i] == -1)
                continue;
            
            adj[n+group[i]].push_back(i);
            indegree[i]++;
        }

        //for inter-group and intra-group dependencies
        for(int i = 0;i<beforeItems.size();i++)
        {
            for(int elem:beforeItems[i])
            {
                //check if beforeItems are inter-group dependent or itra-group
                int a = group[elem] == -1 ? elem : n + group[elem];
                int b = group[i] == -1 ? i : n + group[i];

                //inter-group
                if(a == b)
                {
                    adj[elem].push_back(i);
                    indegree[i]++;
                }
                //intra-group
                else{
                    adj[a].push_back(b);
                    indegree[b]++;
                }
            }
        }

        vector<int> ans;
        for(int i=0;i<n+m;i++)
            if(indegree[i] == 0)
                dfs(i, n, adj, indegree, ans);
        
        return ans.size() == n ? ans : vector<int>{};
    }
};