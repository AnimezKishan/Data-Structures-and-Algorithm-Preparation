// Backtracking

class Solution {
    public:
        void solve(int i, string currStr, string &ans, string &pattern, unordered_map<char, bool> &visited) {
            if(i >= pattern.size()) {
                if(currStr.length() == pattern.size() + 1)
                    ans = min(ans, currStr);
                
                return;
            }
    
            if(currStr == "") {
                for(char ch='1'; ch<='9'; ch++) {
                    visited[ch] = true;
                    solve(i, currStr + ch, ans, pattern, visited);
                    visited[ch] = false;
                }
            }
            else {
                char lastCh = currStr[currStr.length()-1];
                if(pattern[i] == 'I') {
                    for(char ch=char(lastCh+1); ch<='9'; ch++) {
                        if(!visited[ch]){
                            visited[ch] = true;
                            solve(i+1, currStr + ch, ans, pattern, visited);
                            visited[ch] = false;
                        }
                    }
                }
                else {
                    for(char ch=char(lastCh-1); ch>='1'; ch--) {
                        if(!visited[ch]) {
                            visited[ch] = true;
                            solve(i+1, currStr + ch, ans, pattern, visited);
                            visited[ch] = false;
                        }
                    }
                }
            }
        }
        string smallestNumber(string pattern) {
            unordered_map<char, bool> visited;
    
            string ans = "AAAAAAAAA";
            solve(0, "", ans, pattern, visited);
    
            return ans;
        }
    };