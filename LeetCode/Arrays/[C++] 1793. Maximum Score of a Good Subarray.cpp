//Two-Pointer (Greedy)
//In this approach, firstly take as much possible elements from right of k. Then, search for left elements for min element if any.

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int i = k, j = k;
        int currMin = nums[i];
        int result = nums[i];

        while(i > 0 || j < n-1){
            int leftValue = (i > 0 ? nums[i-1] : 0);
            int rightValue = (j < n-1 ? nums[j+1] : 0);

            if(leftValue > rightValue){
                i--;
                currMin = min(currMin, leftValue);
            }
            else{
                j++;
                currMin = min(currMin, rightValue);
            }

            result = max(result, currMin * (j-i+1));
        }

        return result;
    }
};