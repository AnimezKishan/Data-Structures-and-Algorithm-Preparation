// Interval Based

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            int n = intervals.size();
            sort(intervals.begin(), intervals.end());
    
            vector<vector<int>> merged;
            merged.push_back(intervals[0]);
    
            for(int i=1; i<n; i++) {
                if(merged.back()[1] >= intervals[i][0]) {
                    merged.back()[0] = min(intervals[i][0], merged.back()[0]);
                    merged.back()[1] = max(intervals[i][1], merged.back()[1]);
                } else {
                    merged.push_back(intervals[i]);
                }
            }
    
            return merged;
        }
    };