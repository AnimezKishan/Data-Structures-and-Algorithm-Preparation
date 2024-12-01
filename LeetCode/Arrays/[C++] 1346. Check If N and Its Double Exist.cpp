// Similar to Two Sum

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<float, bool> mp;
        
        for(int i=0; i<arr.size(); i++) {
            if(mp.find((float)arr[i]*2) != mp.end() || mp.find((float)arr[i]/2) != mp.end())
                return true;
            else
                mp[float(arr[i])] = true;
        } 

        return false;
    }
};