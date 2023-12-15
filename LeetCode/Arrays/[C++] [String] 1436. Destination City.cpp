// For paths[i] = [cityAi, cityBi], answer would be a minimum occuring city and whose position is in CityB. 
// So, intentionally increasing cityA's count by 2. 

class Solution {
public:

    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> count;
        for(int i=0;i<paths.size();i++){
            string u = paths[i][0];
            string v = paths[i][1];

            count[u] += 2;
            count[v]++;
        }

        int mini = INT_MAX;
        string ans;
        for(auto i:count)
        {
            if(i.second < mini)
            {
                mini = i.second;
                ans = i.first;
            }
        }
        return ans;
    }
};