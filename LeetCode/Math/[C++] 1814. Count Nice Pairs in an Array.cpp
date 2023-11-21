/*
Here, key point is to rearrange the elements of same type.
Lets say, there are
a, b, x = rev(a), y = rev(b)

A/Q :- 
=> a + y = b + x
=> a - x = b - y
*/

class Solution {
public:
    int MOD = 1e9 + 7;
    int rev(int n){
        int res = 0;
        for (; n > 0; n /= 10)
            res = res * 10 + n % 10;
        return res;
    }
    int countNicePairs(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++)
            nums[i] = nums[i] - rev(nums[i]);
        
        long ans = 0;
        unordered_map<int, int> mp;

        for(int i=0;i<nums.size();i++){
            ans = (ans + mp[nums[i]]) % MOD;
            mp[nums[i]]++;
        }

        return ans % MOD;
    }
};