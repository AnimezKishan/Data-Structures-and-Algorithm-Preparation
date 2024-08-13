class Solution {
public:
    void solve(int idx, vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &curr) {
        if(target < 0)
            return;
        
        if(target == 0){
            ans.push_back(curr);
            return;
        }

        for(int i=idx; i<candidates.size(); i++){
            if(i > idx && candidates[i] == candidates[i-1])
                continue;
            
            curr.push_back(candidates[i]);
            solve(i+1, candidates, target-candidates[i], ans, curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        sort(begin(candidates), end(candidates));
        solve(0, candidates, target, ans, curr);
        return ans;
    }
};