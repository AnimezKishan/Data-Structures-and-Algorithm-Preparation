class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i=1;i<points.size();i++){

            // Chebyshev Distance = max( |x2 - x1|, |y2-y1| )
            int chebyshev_distance = max(abs(points[i][0] - points[i-1][0]), abs(points[i][1] - points[i-1][1]));
            ans += chebyshev_distance;
        }

        return ans;
    }
};