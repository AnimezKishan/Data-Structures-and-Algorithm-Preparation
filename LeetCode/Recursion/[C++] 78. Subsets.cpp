// Approach I - Recursion

class Solution {
private:
    void subset(vector<int> &n, vector<vector<int>> &ans, vector<int> output, int i){
        if(i >= n.size())
        {
            ans.push_back(output);
            return;
        }
        //exclude the value
        subset(n, ans, output, i+1);

        //include the value
        int element = n[i];
        output.push_back(element);
        subset(n, ans, output, i+1);

    }
public:
    vector<vector<int>> subsets(vector<int>& n) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        subset(n, ans, output, index);
        return ans;
    }
};


// Approach II - Backtracking

/*
class Solution {
public:
    void solve(vector<int> &nums, int i, vector<vector<int>> &subsets,vector<int> &currSubset){
        if(i == nums.size()){
            subsets.push_back(currSubset);
            return;
        }

        currSubset.push_back(nums[i]);
        solve(nums, i+1, subsets, currSubset);
        currSubset.pop_back();
        solve(nums, i+1, subsets, currSubset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> currSubset;

        solve(nums, 0, subsets, currSubset);
        return subsets;
    }
};
*/