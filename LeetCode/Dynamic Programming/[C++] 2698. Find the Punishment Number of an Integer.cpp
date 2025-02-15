class Solution {
    public:
        bool isPoss(int i, int currSum, string s, int target, vector<vector<int>> &dp) {
            if(i == s.length())
                return currSum == target;
            
            if(currSum > target)
                return false;
    
            if(dp[i][currSum] != -1)
                return dp[i][currSum];
            
            bool isPossible = false;
            for(int j=i; j<s.length(); j++) {
                string sub = s.substr(i, j-i+1);
                int subNum = stoi(sub);
    
                isPossible = isPossible || isPoss(j+1, currSum+subNum, s, target, dp);
                if(isPossible)
                    return true;
            }
    
            return dp[i][currSum] = isPossible;
        }
    
        int punishmentNumber(int n) {
            int sum = 0;
    
            for (int i = 1; i <= n; i++) {
                int num = i * i;
                string s = to_string(num);
    
                vector<vector<int>> dp(s.length(), vector<int>(i+1, -1));
                if (isPoss(0, 0, s, i, dp))
                    sum += num;
            }
    
            return sum;
        }
    };
    