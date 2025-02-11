class Solution {
    public:
        string removeOccurrences(string s, string part) {
            string ans = "";
            int n1 = s.length(), n2 = part.length();
            
            for(char &ch : s) {
                ans.push_back(ch);
    
                if(ans.length() >= n2 && ans.substr(ans.length() - n2) == part) {
                    int tempN = n2;
                    while(tempN--)
                        ans.pop_back();
                }
            }
    
            return ans;
        }
    };

// Another approach
/*
class Solution {
    public:
    string removeOccurrences(string s, string part) {
        while(s.length()!=0 && s.find(part) < s.length())
        {
            s.erase(s.find(part), part.size());
        }
        return s;
    }
};
*/