/*
Firstly sort the array to easily access the min and max elements.

Since moves are at most three, only four ways are possible.
Example, 
Array after sorting: [0, 2, 3, 5, 6, 10, 11, 14]
    -> change first three element: [5, 5, 5, 5, 6, 10, 11, 14] = 14-5 = 9 (nums[n-1] - nums[3])
    -> change last three elements: [0, 2, 3, 5, 6, 6, 6, 6] = 6-0 = 6 (nums[n-4] - nums[0])
    -> change first two and last element: [3, 3, 3, 5, 6, 10, 11, 11] = 11-3 = 9 (nums[n-2] - nums[2])
    -> change last two and first element: [2, 2, 3, 5, 6, 10, 10, 10] = 10-2 = 8 (nums[n-3] - nums[1])
*/

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();

        if(n <= 3)
            return 0;
        
        int ans = INT_MAX;
        sort(begin(nums), end(nums));
        for(int i=0; i<=3; i++)
            ans = min(ans, (nums[n-4+i] - nums[i]));

        return ans;
    }
};