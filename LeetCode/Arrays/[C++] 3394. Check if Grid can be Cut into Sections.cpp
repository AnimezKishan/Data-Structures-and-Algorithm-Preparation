// Interval Based
// Pre-Requisite: Leetcode 56

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>> &intervals) {
            int n = intervals.size();
            sort(intervals.begin(), intervals.end());
    
            vector<vector<int>> merged;
            merged.push_back(intervals[0]);
    
            for(int i=1; i<n; i++) {
                if(merged.back()[1] > intervals[i][0]) {
                    merged.back()[0] = min(intervals[i][0], merged.back()[0]);
                    merged.back()[1] = max(intervals[i][1], merged.back()[1]);
                } else {
                    merged.push_back(intervals[i]);
                }
            }
    
            return merged;
        }
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            vector<vector<int>> hor; // x-axis
            vector<vector<int>> vert; // y-axis
    
            for(vector<int> &rect : rectangles) {
                int x1 = rect[0];
                int y1 = rect[1];
                int x2 = rect[2];
                int y2 = rect[3];
    
                hor.push_back({ x1, x2 });
                vert.push_back({ y1, y2 });
            }
    
            vector<vector<int>> mergedX = merge(hor);
            vector<vector<int>> mergedY = merge(vert);
    
            // in any of x-axis or y-axis, if we have 3 or more intervals then we can draw two cuts
            return mergedX.size() >= 3 || mergedY.size() >= 3; 
        }
    };