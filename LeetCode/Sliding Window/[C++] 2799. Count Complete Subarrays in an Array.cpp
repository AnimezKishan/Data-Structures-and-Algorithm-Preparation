class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            unordered_map<int, int> mp;
            for(int &num : nums) 
                mp[num]++;
            
            int distinctNo = mp.size(), i = 0, j = 0, n = nums.size();
            mp.clear();
            int ans = 0;
            while(j < n) {
                mp[nums[j]]++;
    
                while(mp.size() == distinctNo) {
                    // Since distinctNo is upmost value of distinct elements. So, subarray from here till n will be valid.
                    ans += (n-j);
                    mp[nums[i]]--;
                    if(mp[nums[i]] == 0)
                        mp.erase(nums[i]);
                    
                    i++;
                }
    
                j++;
            }
    
            return ans;
        }
    };