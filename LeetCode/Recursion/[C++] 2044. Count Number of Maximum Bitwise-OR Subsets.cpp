class Solution {
public:
    int n, ans = 0;
    void solve(int idx, int currOr, vector<int> &nums, int &maxOr) {
        if(idx == n){
            if(currOr == maxOr)
                ans++;
            return;
        }
        
        // take 
        solve(idx+1, currOr | nums[idx], nums, maxOr);

        // don't take
        solve(idx+1, currOr, nums, maxOr);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        n = nums.size();
        int maxOr = nums[0];
        for(int i=1; i<n; i++) {
            maxOr = maxOr | nums[i];
        }

        solve(0, 0, nums,maxOr);
        return ans;
    }
};