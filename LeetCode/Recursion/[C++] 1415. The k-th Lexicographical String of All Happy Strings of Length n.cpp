class Solution {
    public:
        void solve(int i, int &currK, string currStr, int n, int k, vector<string> &happyStrings) {
            if(i >= n) {
                if (currK == k)
                    return;
                happyStrings.push_back(currStr);
                currK++; 
                return;
            }
    
            for(char ch='a'; ch<='c'; ch++) {
                if(currK == k)
                    return;
    
                if(currStr == "")
                    solve(i+1, currK, currStr + ch, n, k, happyStrings);
                else {
                    if(currStr[currStr.length() - 1] != ch) {
                        solve(i+1, currK, currStr + ch, n, k, happyStrings);
                    }
                }
            }
        }
        string getHappyString(int n, int k) {
            vector<string> happyStrings;
            int currK = 0;
            solve(0, currK, "", n, k, happyStrings);
    
            return k > happyStrings.size() ? "" : happyStrings[happyStrings.size() - 1];
        }
    };