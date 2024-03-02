// Two - Pointer
// Since, given integer array nums sorted in non-decreasing order. We can compare no.s and put the largest into right.

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1;
        int temp;
        vector<int> ans(n);

        for(int i=n-1;i>=0;i--){
            if(abs(nums[left]) > abs(nums[right])){
                temp = nums[left];
                left++;
            }
            else{
                temp = nums[right];
                right--;
            }

            ans[i] = temp*temp;
        }

        return ans;
    }
};