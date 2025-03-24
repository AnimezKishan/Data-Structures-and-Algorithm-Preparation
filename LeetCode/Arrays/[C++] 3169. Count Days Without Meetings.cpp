// Interval Based

class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            sort(meetings.begin(), meetings.end());
    
            int ans = 0, end = 0;
            for(vector<int> &meet : meetings) {
                if(meet[0] > end) {
                    ans += meet[0] - end - 1;
                }
                end = max(end, meet[1]);
            }
    
            // leftover days if no more meetings to be conducted
            if(end < days) {
                ans += days - end;
            }
    
            return ans;
        }
    };