class Solution {
    public:
        int countLargestGroup(int n) {
            int maxGroupSize = 0;
            int maxCount = 0;
            unordered_map<int, int> mp;
    
            for(int i=1; i<=n; i++) {
                int num = i;
                int currSum = 0;
                while(num) {
                    currSum += num%10;
                    num /= 10;
                }
    
                mp[currSum]++;
    
                if(mp[currSum] > maxGroupSize) {
                    maxGroupSize = mp[currSum];
                    maxCount = 1;
                } else if(mp[currSum] == maxGroupSize) {
                    maxCount++;
                }
            }
    
            return maxCount;
        }
    };