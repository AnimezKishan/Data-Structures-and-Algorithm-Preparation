//Important!!
/*
Recursive Stack Flow :-
https://miro.medium.com/v2/resize:fit:720/format:webp/1*cH8mDg-iT6WfAiNYwIw8hg.png
*/
class Solution {
private:
    void solve(vector<int> n, vector<vector<int>> &ans, int index){
        if(index>=n.size())
        {
            ans.push_back(n);
            return;
        }
        for(int i=index; i<n.size();i++){
            swap(n[i], n[index]);
            solve(n, ans, index+1);
            //backtrack
            swap(n[i], n[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index=0;
        solve(nums, ans, index);
        return ans;
    }
};