class Solution {
public:
    int ans = 0;
    unordered_map<int, int> m;
    void solve(int idx, vector<int> &nums, int k) {
        if(idx == nums.size()){
            ans++;
            return;
        }

        // exclude
        solve(idx+1, nums, k);

        //inlcude + check for condition
        /*
        condition example: 
        let's say k = 2,
        To inlcude 4, which values shouldn't be taken such that abs(n - 4) != k i.e abs(n - 4) != 2
        So, the no.s would be (4 - k) and (4 + k) i.e. 2 and 6.
        */
        if(!m[nums[idx] - k] && !m[nums[idx] + k]){
            m[nums[idx]]++;
            solve(idx+1, nums, k);
            m[nums[idx]]--;
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        solve(0, nums, k);

        // exclude empty subset
        return ans - 1;
    }
};