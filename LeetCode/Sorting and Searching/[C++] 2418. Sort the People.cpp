class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<string, int>> vec(n);
        for(int i=0; i<n; i++){
            vec[i] = {names[i], heights[i]};
        }

        auto lambda = [&](pair<string, int> &v1, pair<string, int> &v2){
            return v1.second > v2.second;
        };
        
        sort(begin(vec), end(vec), lambda);

        for(int i=0; i<n; i++){
            names[i] = vec[i].first;
        }

        return names;
    }
};


/*
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        auto lambda = [&](int i, int j){
            return heights[i] > heights[j];
        };

        sort(begin(idx), end(idx), lambda);
        vector<string> ans;
        for(int &i : idx){
            ans.push_back(names[i]);
        }

        return ans;
    }
};
*/