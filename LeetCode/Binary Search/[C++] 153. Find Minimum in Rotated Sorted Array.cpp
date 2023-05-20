class Solution {
private:
    int findPivot(vector<int> &n, int s, int e){
        while(s<e){
            int mid = s+(e-s)/2;
            if(n[mid] >= n[0]){
                s = mid+1;
            }
            else
                e = mid;
        }
        return s;
    }
public:
    int findMin(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int pivot = findPivot(nums, s, e);

        //Means No Rotation, the vector is properly sorted already.
        if(nums[s] < nums[e])
            return nums[0];
        else
            return nums[pivot];        
    }
};