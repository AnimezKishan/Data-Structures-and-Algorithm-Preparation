class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            int n = nums.size();
            // ** For an array of size n, no. of subarray defined by a contiguous range [i,j] where i<j is : n * (n-1) / 2  
            long long totalSubarr = (1LL * n * (n-1))/2;
            unordered_map<int, int> mp;
    
            // Notice that (j - i != nums[j] - nums[i]) is the same as (nums[i] - i != nums[j] - j)
            // So, remove the good pairs from all pairs
            for(int i=0; i<n; i++) {
                int x = nums[i] - i;
                if(mp.find(x) != mp.end())
                    totalSubarr -= mp[x];
                
                mp[x]++;
            }
    
            return totalSubarr;
        }
    };