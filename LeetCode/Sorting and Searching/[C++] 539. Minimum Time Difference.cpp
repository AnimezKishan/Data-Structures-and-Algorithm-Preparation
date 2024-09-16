class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> minutes(n);

        for(int i=0; i<n; i++) {
            string hr = timePoints[i].substr(0, 2);
            hr = hr == "00" ? "24" : hr;
            string min = timePoints[i].substr(3, 2);

            // hh:mm to minutes conversion
            minutes[i] = stoi(hr)*60 + stoi(min);
        }

        sort(begin(minutes), end(minutes));
        int ans = INT_MAX;

        // for minimum time difference, check for adjacent minutes
        for(int i=0; i<n-1; i++) {
            int t1 = minutes[i];
            int t2 = minutes[i+1];
        
            ans = min(ans, t2 - t1);
        }

        // since time is cyclic, we need to check first and last time minutes
        return min(ans, minutes[0] + 1440 - minutes[n-1]);
    }
};