// Backtracking

class Solution {
public:
    vector<vector<string>> ans;
    vector<string> curr;

    bool isPalindrome(string &s, int i, int j){
        while(i<j)
            if(s[i++] != s[j--])
                return false;
        
        return true;
    }
    void solve(string &s, int idx){
        if(idx == s.length()){
            ans.push_back(curr);
            return;
        }

        for(int i=idx;i<s.length();i++){
            if(isPalindrome(s, idx, i)){
                curr.push_back(s.substr(idx, i-idx+1));
                solve(s, i+1);
                curr.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        solve(s, 0);
        return ans;
    }
};