/*
Since range of numbers in array = [0, n]
and range of indices of nums array = [0, n-1].

So, take a variable with value as 'n', this way, number which gets found out twice either from index or array element gets cancelled out. 
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int result = n;

        for(int i=0;i<n;i++){
            result ^= i ^ nums[i];
        }

        return result;
    }
};