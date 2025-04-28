class Solution {
    public:
        long long countSubarrays(vector<int>& nums, long long k) {
            long long sum = 0, ans = 0;
            int i = 0, j = 0, count = 0;
    
            while(j < nums.size()) {
                sum += nums[j];
                count++;
    
                while(sum*count >= k) {
                    sum -= nums[i];
                    count--;
    
                    i++;
                }
    
                ans += j-i+1;
                j++;
            }
    
            return ans;
        }
    };