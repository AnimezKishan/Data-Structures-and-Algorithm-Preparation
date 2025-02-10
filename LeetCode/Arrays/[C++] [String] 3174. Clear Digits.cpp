class Solution {
    public:
        string clearDigits(string s) {
            string ans = "";
    
            for(char &ch : s) {
                if(ch >= '0' && ch <= '9' && !ans.empty())
                    ans.pop_back();
                else
                    ans += ch;
            }
    
            return ans;
        }
    };