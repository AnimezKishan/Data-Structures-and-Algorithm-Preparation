class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;

        for(int &i:arr)
            mp[i]++;
        
        unordered_map<int, int> occurance;

        for(auto &i:mp){
            occurance[i.second]++;

            if(occurance[i.second] > 1)
                return false;
        }

        return true;
    }
};