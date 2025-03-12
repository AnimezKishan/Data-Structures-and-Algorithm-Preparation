class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int n = nums.size();
            int negIndex = 0, s = 0, e = n - 1;
            while(s <= e) {
                int mid = s + (e-s)/2;
                if(nums[mid] < 0){
                    negIndex = mid;
                    s = mid+1;
                }
                else
                    e = mid-1;
            }
    
            int negCount = 0;
            if(nums[negIndex] < 0)
                negCount = negIndex + 1;
            
            s = (nums[negIndex] >= 0) ? negIndex : negIndex+1, e = n - 1;
            int posIndex = 0;
            while(s <= e) {
                int mid = s + (e-s)/2;
    
                if(nums[mid] > 0) {
                    posIndex = mid;
                    e = mid - 1;
                }
                else 
                    s = mid + 1;
            } 
    
            int posCount = (nums[posIndex] > 0) ? n - posIndex : 0;
            return max(posCount, negCount);
        }
    };