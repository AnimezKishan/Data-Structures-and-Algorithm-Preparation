// Two - Pointer

class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            int n = nums.size();
            for(int i=0; i<n-1; i++) {
                if(nums[i] == nums[i+1]){
                    nums[i] *= 2;
                    nums[i+1] = 0; 
                }
            }
    
            vector<int> shiftedArr(n);
            int i = 0, j = n-1;
            for(int k=0; k<n; k++) {
                if(nums[k] == 0)
                    shiftedArr[j--] = nums[k];
                else
                    shiftedArr[i++] = nums[k];
            }
            return shiftedArr;
        }
    };