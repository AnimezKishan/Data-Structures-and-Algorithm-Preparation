// Hashmap + Max Heap

class Solution {
    public:
        int maximumSum(vector<int>& nums) {
            unordered_map<long long int, priority_queue<int>> mp;
            for(int i=0; i<nums.size(); i++) {
                int temp = nums[i], currSum = 0;
                while(temp) {
                    currSum += temp % 10;
                    temp /= 10;
                }
    
                mp[currSum].push(nums[i]);
            }
    
            int maxVal = -1;
            for(auto i : mp) {
                if(mp[i.first].size() > 1) {
                    int last = mp[i.first].top();
                    mp[i.first].pop();
                    int secondLast = mp[i.first].top();
                    
                    maxVal = max(maxVal, last + secondLast);
                }
            }
    
            return maxVal;
    
        }
    };