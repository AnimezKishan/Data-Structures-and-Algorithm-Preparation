class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(begin(events), end(events));

        vector<int> suffixMax(events.size());
        suffixMax[n-1] = events[n-1][2];
        for(int i=n-2; i>=0; i--) {
            suffixMax[i] = max(events[i][2], suffixMax[i+1]);
        }
        int ans = 0;
        for (vector<int>& event : events) {
            int startTime = event[0];
            int endTime = event[1];
            int value = event[2];

            auto it = upper_bound(events.begin(), events.end(), vector<int>({endTime, (int)1e9, (int)1e9}));
            int upperIndex = it - events.begin();

            ans = max(ans, value);
            if(upperIndex != n) 
                ans = max(ans, value + suffixMax[upperIndex]);
        }

        return ans;
    }
};
