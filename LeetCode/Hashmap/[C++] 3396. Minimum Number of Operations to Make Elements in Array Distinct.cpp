// Instead of simulating the removal of 3 elements every time, try traversing the array from the end. The goal is to find the first index i where a duplicate is encountered.


class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            int n = nums.size();
            unordered_map<int, bool> mp;
    
            for(int i=n-1; i>=0; i--) {
                if(mp.find(nums[i]) != mp.end()) {
                    if((i+1)%3) {
                        return (i+1)/3 + 1;
                    }
                    else {
                        return (i+1)/3;
                    }
                }
    
                mp[nums[i]] = true;
            }
    
            return 0;
        }
    };