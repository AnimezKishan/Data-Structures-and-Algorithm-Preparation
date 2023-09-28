//Two Pointer

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        while(i<j){
            if(nums[i]%2 == 1){
                swap(nums[i], nums[j]);
                j--;
            }
            else
                i++;
        }
        return nums;
    }
};