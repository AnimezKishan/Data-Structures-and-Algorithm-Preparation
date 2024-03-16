/*
Treat 0 as -1
Make a map which maps cummulative sum to index.
Similar to 560, Cummulative Sum + Map
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> pSumToIndex;

        int pSum = 0, ans = 0;
        pSumToIndex[0] = -1;
        for(int i=0;i<nums.size();i++){
            pSum += (nums[i] == 0) ? -1 : 1;
            
            if(pSumToIndex.find(pSum) != pSumToIndex.end())
                ans = max(ans, i-pSumToIndex[pSum]);
            else
                pSumToIndex[pSum] = i;
        }

        return ans;
    }
};