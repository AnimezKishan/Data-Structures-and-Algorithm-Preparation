class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            unordered_map<int, int> mp;
            for(int &num : nums)
                mp[num]++;
    
            for(auto &i : mp){
                if(mp[i.first]&1)
                    return false;
            } 
    
            return true;
        }
    };