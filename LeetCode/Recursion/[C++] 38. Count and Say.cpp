// Iterative Approach
class Solution {
    public:
        void countHelper(string &str, vector<pair<int, int>> &mp) {
            int i = 0, j = 0;
            while(i<str.size()) {
                char ch = str[i];
                j = i+1;
                while(j<str.size() && str[j] == ch) 
                    j++;
                
                int count = j - i;
                mp.push_back({ count, ch-'0' });
                i = j;
            }
        }
    
        void mergeHelper(string &str, vector<pair<int, int>> &mp) {
            str = "";
            for(pair<int, int> &p : mp) {
                str += to_string(p.first);
                str += to_string(p.second);
            }
        }
        string countAndSay(int n) {
            if(n == 1)
                return "1";
            
            string str = "1";
            for(int i=0; i<n-1; i++) {
                vector<pair<int, int>> mp; // count, num pair
    
                countHelper(str, mp);
                mergeHelper(str, mp);
            }
    
            return str;
        }
    };


// Recursive Approach
class Solution {
    public:
        string solve(int n) {
            if(n == 1)
                return "1";
            
            string initial = solve(n-1);
            string final = "";
            int i = 0, j = 0;
            while(i<initial.size()) {
                char ch = initial[i];
                j = i+1;
                while(j<initial.size() && initial[j] == ch) 
                    j++;
                
                int count = j - i;
                final += to_string(count) + ch;
                i = j;
            }
    
            return final;
        }
        string countAndSay(int n) {
            return solve(n);
        }
    };