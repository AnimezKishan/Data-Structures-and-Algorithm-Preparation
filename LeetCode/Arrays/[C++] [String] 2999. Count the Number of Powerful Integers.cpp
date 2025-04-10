class Solution {
    public:
        long long solve(string &str, string &suffix, int limit) {
            if(str.length() < suffix.length())
                return 0;
    
            long long count = 0;
            string trailString = str.substr(str.length() - suffix.length());
            int remainingLen = str.length() - suffix.length();
    
            for(int i=0; i<remainingLen; i++) {
                int digit = str[i] - '0';
    
                if(digit <= limit) {
                    count += digit * pow(limit+1, remainingLen-i-1);
                } else {
                    count += pow(limit+1, remainingLen-i);
                    return count;
                }
            }
    
            if(trailString >= suffix) 
                    count++;
            
            return count;
        }
        long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
            string startingStr = to_string(start-1);
            string endingStr = to_string(finish);
    
            return solve(endingStr, s, limit) - solve(startingStr, s, limit);
        }
    };