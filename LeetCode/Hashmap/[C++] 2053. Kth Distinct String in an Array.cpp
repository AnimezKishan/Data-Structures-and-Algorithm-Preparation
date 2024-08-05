class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        for(string &str : arr)
            mp[str]++;
        
        int kCount = 0;
        for(string &str : arr){
            if(mp[str] == 1)
                kCount++;
            
            if(kCount == k)
                return str;
        }

        return "";
    }
};