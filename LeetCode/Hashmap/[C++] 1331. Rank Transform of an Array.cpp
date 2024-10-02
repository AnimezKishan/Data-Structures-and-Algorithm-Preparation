class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        sort(begin(temp), end(temp));

        unordered_map<int, int> mp;
        int rank = 1;
        for(int &i : temp) {
            if(mp.find(i) == mp.end()){
                mp[i] = rank++;
            }
        }

        for(int i=0; i<arr.size(); i++) {
            arr[i] = mp[arr[i]];
        }

        return arr;
    }
};