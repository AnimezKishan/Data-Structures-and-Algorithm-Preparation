class Solution {
public:
    vector<string> ans;
    unordered_map<string, bool> m;
    void solve(int idx, string &s, string temp, string currString) {
        if(idx == s.length()){
            if(temp == ""){
                currString.pop_back();
                ans.push_back(currString);
            }
            
            return;
        }

        temp += s[idx];

        if(m[temp]) {
            //take 
            string tempAdd = (temp + " ");
            solve(idx+1, s, "", currString+tempAdd);
            
            // not take
            solve(idx+1, s, temp, currString);

        }
        else
            solve(idx+1, s, temp, currString);
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string &s : wordDict)
            m[s] = true;
        
        string currString = "";
        solve(0, s, "", currString);
        return ans;
    }
};