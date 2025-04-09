class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            vector<bool> visited(101, false);
    
            // return the number of distinct integers in the array that are greater than k.
            int distinct = 0;
            for(int &num : nums) {
                if(num < k)
                    return -1;
                    
                if(visited[num] == false && num > k) {
                    distinct++;
                    visited[num] = true;
                }
            }
    
            return distinct;
        }
    };