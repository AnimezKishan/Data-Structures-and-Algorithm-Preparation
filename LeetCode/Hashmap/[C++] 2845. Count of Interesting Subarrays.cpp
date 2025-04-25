class Solution {
    public:
        long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
            for(int i=0; i<nums.size(); i++) {
                if(nums[i] % modulo == k)
                    nums[i] = 1;
                else
                    nums[i] = 0;
            }
    
            unordered_map<int, long long> mp;
            mp[0] = 1;
            long long ans = 0;
            long long sum = 0;
    
            for(int num : nums) {
                sum += num;
    
                int r1 = sum % modulo;
    
                int r2 = (r1 - k + modulo) % modulo;
    
                if(mp.find(r2) != mp.end())
                    ans += mp[r2];
                
                mp[r1]++;
            }
    
            return ans;
        }
    };