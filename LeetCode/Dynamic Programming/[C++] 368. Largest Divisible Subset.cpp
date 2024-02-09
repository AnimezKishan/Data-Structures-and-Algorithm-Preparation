// LIS Varient

class Solution {
public:
    vector<int> ans;
    int dp[1001];
    int n;
    void solve(int i, vector<int> &nums, int prev,vector<int> temp){
        if(i >= n){
            if(temp.size() > ans.size())
                ans = temp;
            return;
        }

        if((int)temp.size() > dp[i] && nums[i] % prev == 0){
            dp[i] = temp.size();
            temp.push_back(nums[i]);
            //take
            solve(i+1, nums, nums[i], temp);
            temp.pop_back();
        }

        //don't take
        solve(i+1, nums, prev, temp);

    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        sort(begin(nums), end(nums));
        solve(0, nums, 1,{});
        return ans;
    }
};

// Recursion (gives TLE)
/*
class Solution {
public:
    vector<int> ans;
    int n;
    void solve(int i, vector<int> &nums, int prev,vector<int> temp){
        if(i >= n){
            if(temp.size() > ans.size())
                ans = temp;
            return;
        }

        if(temp.empty() || nums[i] % temp.back() == 0){
            temp.push_back(nums[i]);
            //take
            solve(i+1, nums, nums[i], temp);
            temp.pop_back();
        }

        //don't take
        solve(i+1, nums, prev, temp);

    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        n = nums.size();
        sort(begin(nums), end(nums));
        solve(0, nums, 1, {});
        return ans;
    }
};
*/