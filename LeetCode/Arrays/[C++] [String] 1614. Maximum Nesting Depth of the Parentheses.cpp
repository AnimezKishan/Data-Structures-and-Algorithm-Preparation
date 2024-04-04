class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int count = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '(')
                count++;
            else if(s[i] == ')')
                count--;
            
            ans = max(ans, count);
        }
        return ans;
    }
};