// Two - Pointer

class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            int n = nums.size();
            int pivotIndex = 0, pivotCount = 0;
            for(int i=0; i<n; i++) {
                if(nums[i] < pivot)
                    pivotIndex++;
                
                if(nums[i] == pivot)
                    pivotCount++;
            }
    
            int i = 0, j = pivotIndex + pivotCount;
            vector<int> ans(n);
            for(int k=0; k<n; k++) {
                if(nums[k] < pivot)
                    ans[i++] = nums[k];
                else if(nums[k] > pivot)
                    ans[j++] = nums[k];
                else
                    ans[pivotIndex++] = nums[k];
            }
    
            return ans;
        }
    };