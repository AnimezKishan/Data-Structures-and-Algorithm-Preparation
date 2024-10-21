class Solution {
public:
    int n;
    void solve(int idx, string &s, int currCount, int &maxCount, unordered_set<string> &st) {
        if(idx >= n) {
            maxCount = max(maxCount, currCount);
            return;
        }

        for(int j=idx; j<n; j++) {
            string subStr = s.substr(idx, j-idx+1);
            if(st.find(subStr) == st.end()){
                st.insert(subStr);
                solve(j+1, s, currCount+1, maxCount, st);
                st.erase(subStr);
            }
        }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        n = s.length();
        int maxCount = 0;

        solve(0, s, 0, maxCount, st);
        return maxCount;
    }
};