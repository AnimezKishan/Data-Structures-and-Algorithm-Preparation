// Approach II - [Generate all subsets and calculate sum XOR simultaneously]  
// T.C. -> O(2^n) [no need to store and iterate on all subsets]
// S.C. -> O(n) [System Stack Space for Recursion]

class Solution {
public:
    // Generating all possible subsets using Backtracking and storing sum XOR simultaneously
    int solve(vector<int>& nums, int i, int XOR) {
        if(i == nums.size())
            return XOR;
        
        int include = solve(nums, i+1, nums[i]^XOR);
        int exclude = solve(nums, i+1, XOR);

        return include + exclude;
    }
    int subsetXORSum(vector<int>& nums) {
        return solve(nums, 0, 0);
    }
};


// Approach I - Brute Force [ Generate and store all subsets and iterate to calculate XORs ]
// T.C - O(2^n * L), L = average length of subset.
// S.C - O(2^n * L)
/*
class Solution {
public:
    // Generating all possible subsets using Backtracking
    void solve(vector<int>& nums, int i, vector<int>& currSubset, vector<vector<int>>& subsets) {
        if(i == nums.size()){
            subsets.push_back(currSubset);
            return;
        }

        currSubset.push_back(nums[i]);
        solve(nums, i+1, currSubset, subsets);
        currSubset.pop_back();
        solve(nums, i+1, currSubset, subsets);
    }
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subsets;

        vector<int> currSubset;
        
        solve(nums, 0, currSubset, subsets);

        int ans = 0, currXOR = 0;
        for(vector<int>& subset:subsets){
            currXOR = 0;
            for(int n : subset){
                currXOR ^= n;
            }

            ans += currXOR;
        }

        return ans;
    }
};
*/