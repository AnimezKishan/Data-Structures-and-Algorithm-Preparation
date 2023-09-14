/*
T.C -> O(v)^2
DFS + Backtracking
*/

class Solution {
public:
    int numTicket = 0;
    vector<string> ans;
    unordered_map<string, vector<string>> adj;

    bool dfs(string fromCity, vector<string> &path)
    {
        path.push_back(fromCity);

        if(path.size() == numTicket+1)
        {
            ans = path;
            return true;
        }

        auto &nbr = adj[fromCity];

        for(int i=0;i<nbr.size();i++)
        {
            string toCity = nbr[i];

            nbr.erase(nbr.begin()+i);

            if(dfs(toCity, path))
                return true;
            
            nbr.insert(nbr.begin()+i, toCity);
        }

        path.pop_back();
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        numTicket = tickets.size();

        for(auto &t:tickets)
            adj[t[0]].push_back(t[1]);
        
        for(auto &edges:adj)
            sort(begin(edges.second), end(edges.second));
        
        vector<string> path;
        dfs("JFK", path);
        return ans;
    }
};