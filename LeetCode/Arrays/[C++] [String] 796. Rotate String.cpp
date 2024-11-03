class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length())
            return false;
        
        int n = goal.length(), j = 0;
        while(j < n) {
            if(s[j] == goal[0]){
                int i = 0, temp = j;
                while(i<n) {
                    if(s[temp%n] != goal[i])
                        break;
                    
                    i++;
                    temp++;
                }

                if(i == n)
                    return true;
            }
            
            j++;
        }
        
        return false;
    }
};