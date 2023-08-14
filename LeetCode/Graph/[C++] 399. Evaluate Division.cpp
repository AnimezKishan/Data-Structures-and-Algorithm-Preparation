class Solution {
public:
    double solve(unordered_map<string, vector<pair<string, double>>> adjList, vector<string> query)
    {
        queue<pair<string, double>> q;
        q.push({query[0], 1});
        unordered_set<string> visited;

        while(!q.empty())
        {
            auto t = q.front();
            string s = t.first;
            double val = t.second;
            q.pop();

            visited.insert(s);

            //Either the equation is being applied on itself or the destination equation is reached
            //It also checks if the element is present as equation or not.
            if(s == query[1] && adjList.find(s) != adjList.end())
                return val;
            
            for(auto i:adjList[s])
            {
                //if equation is not visited
                if(visited.find(i.first) == visited.end())
                    q.push({i.first, (double)i.second*val});
            }
        }

        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adjList;
        for(int i=0;i<values.size();i++)
        {
            adjList[equations[i][0]].push_back({equations[i][1], values[i]});
            adjList[equations[i][1]].push_back({equations[i][0], (double)1/values[i]});
        }

        vector<double> ans(queries.size());
        for(int i=0;i<queries.size();i++)
        {
            ans[i] = solve(adjList, queries[i]);
        }
        return ans;
    }
};