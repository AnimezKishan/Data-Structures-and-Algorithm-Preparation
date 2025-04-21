class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            int curr = 0;
            int minVal = 0, maxVal = 0;
    
            for(int &diff : differences) {
                curr = curr + diff;
    
                minVal = min(minVal, curr);
                maxVal = max(maxVal, curr);
    
                if((upper - maxVal) - (lower - minVal) + 1 <= 0)
                    return 0;
            }
    
            return (upper - maxVal) - (lower - minVal) + 1;
        }
    };