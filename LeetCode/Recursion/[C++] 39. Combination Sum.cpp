class Solution {
public:
    void solve(int idx, vector<int>& candidates, int target, vector<int> &curr, vector<vector<int>> &ans){
        if(target < 0)
            return;
        
        if(target == 0){
            ans.push_back(curr);
            return;
        }

        for(int i=idx; i<candidates.size(); i++){
            curr.push_back(candidates[i]);
            solve(i, candidates, target-candidates[i], curr, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target, curr, ans);
        return ans;
    }
};