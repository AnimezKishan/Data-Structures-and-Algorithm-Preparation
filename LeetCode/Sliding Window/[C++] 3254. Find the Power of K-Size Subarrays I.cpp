// Brute Force
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size(), i = 0, j = 0;
        int currCount = 0;
        while(j < n) {
            if(j+1 < n && nums[j+1]-nums[j] == 1)
                currCount++;
            
            while(j-i+1 > k){
                if(nums[i+1] - nums[i] == 1)
                    currCount--;
            }

            if(j-i+1 == k && currCount == k-1){
                ans.push_back();
            } 
            else if(j-i+1 == k)
                ans.push_back(-1);
        } 
    }
};