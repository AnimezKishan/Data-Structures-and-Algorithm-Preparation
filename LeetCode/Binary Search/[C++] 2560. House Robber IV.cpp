class Solution {
    public:
        bool isPoss(vector<int> &nums, int k, int mid) {
            int houses = 0;
            for(int i = 0; i<nums.size(); i++) {
                if(nums[i] <= mid) {
                    houses++;
                    i++;
                }
            }
    
            return houses >= k;
        }
        int minCapability(vector<int>& nums, int k) {
            int s = INT_MAX, e = INT_MIN;
            for(int &num : nums) {
                s = min(s, num);
                e = max(e, num);
            }
    
            int minCap;
            while(s <= e) {
                int mid = s + (e-s)/2;
                if(isPoss(nums, k, mid)){
                    minCap = mid;
                    e = mid - 1;
                }
                else
                    s = mid + 1;
            }
    
            return minCap;
        }
    };