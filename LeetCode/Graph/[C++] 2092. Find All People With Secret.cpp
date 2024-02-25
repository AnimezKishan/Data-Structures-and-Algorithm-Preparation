// Dijkstra's Algorithm

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int, vector<pair<int, int>>> adj;

        for(vector<int> &meeting: meetings){
            int u = meeting[0];
            int v = meeting[1];
            int time = meeting[2];

            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        vector<int> earliest(n, INT_MAX);
        earliest[0] = 0;
        earliest[firstPerson] = 0;

        queue<pair<int, int>> q;
        q.push({0, 0});
        q.push({firstPerson, 0});

        while(!q.empty()){
            auto t = q.front();
            int person1 = t.first;
            int time1 = t.second;
            q.pop();

            for(auto &i:adj[person1]){
                int person2 = i.first;
                int time2 = i.second;

                if(time1 <= time2 && time2 < earliest[person2]){
                    earliest[person2] = time2;
                    q.push({person2, time2});
                }
            }
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(earliest[i] != INT_MAX)
                ans.push_back(i);
        }

        return ans;
    }
};