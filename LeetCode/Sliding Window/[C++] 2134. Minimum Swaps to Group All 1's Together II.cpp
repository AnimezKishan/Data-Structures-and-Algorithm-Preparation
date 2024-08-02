/*
Tip for any problem involving circular array:
    make the array of 2n size with repeating its elements.
e.x: [1,1,0,1] => [1,1,0,1,1,1,0,1]
*/

// Sliding Window
// find the window with max no. of ones in it.
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(2*n);
        int noOfOnes = 0;
        for(int i=0; i<2*n; i++){
            vec[i] = nums[i%n];

            if(i < n && nums[i] == 1)
                noOfOnes++;
        }

        int i = 0, j = 0;
        int currCount = 0;
        int maxCount = 0;
        while(j < 2*n){
            if(vec[j] == 1)
                currCount++;
            
            if(j-i+1 > noOfOnes){
                currCount -= vec[i];
                i++;
            }

            maxCount = max(maxCount, currCount);
            j++;
        }
        return noOfOnes - maxCount;
    }
};