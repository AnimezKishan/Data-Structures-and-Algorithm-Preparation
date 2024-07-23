class Solution {
public:

    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int &num : nums){
            mp[num]++;
        }
        
        auto lambda = [&](int &n1, int &n2){
            if(mp[n1] == mp[n2])
                return n1 > n2;
            
            return mp[n1] < mp[n2];
        };

        sort(begin(nums), end(nums), lambda);
        return nums;
    }
};