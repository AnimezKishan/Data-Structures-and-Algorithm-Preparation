// Interval Based

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(begin(points), end(points));

        vector<int> prevBallon = points[0]; 
        int ans = 1;
        for(int i=1;i<n;i++){
            vector<int> currBallon = points[i];
            if(prevBallon[1] < currBallon[0]){
                ans++;
                prevBallon = currBallon;
            }
            else{
                // overlapping
                prevBallon[0] = max(prevBallon[0], currBallon[0]);
                prevBallon[1] = min(prevBallon[1], currBallon[1]);
            }
        }
        
        return ans;
    }
};