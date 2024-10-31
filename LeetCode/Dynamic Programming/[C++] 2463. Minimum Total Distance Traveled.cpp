class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
    vector<int> factories;
    for (auto &f : factory) {
        int id = f[0];
        int times = f[1];
        while (times--) {
            factories.push_back(id);
        }
    }

    sort(robot.begin(), robot.end());
    sort(factories.begin(), factories.end());

    int r = robot.size();
    int f = factories.size();
    
    vector<vector<long long>> dp(r + 1, vector<long long>(f + 1, LLONG_MAX));
    fill(dp[0].begin(), dp[0].end(), 0); // No robots, so minimum distance is 0

    for (int i = 1; i <= r; i++) {
        dp[i][0] = LLONG_MAX;
        for (int j = 1; j <= f; j++) {
            // On every new factory we have 2 choices:
            // dist(i -> j) & (i-1, j-1) | Now we've new factory 'j' at our disposal, We can assign ith robot to jth factory
            // (i, j-1) | Skip the new factory and use the previous 'j-1' factories
            // Note: We don't assign other robots to this 'jth' factory bcoz on the timeline they're behined the ith robot means there distance will always be greater that the ith robot to this new factory.
            // If we've any chance of minimising the total distance, it is with the ith robot only.
            dp[i][j] = min(dp[i][j-1], 
                        (dp[i-1][j-1] != LLONG_MAX ? abs((long long)robot[i-1] - (long long)factories[j-1]) + dp[i-1][j-1] : LLONG_MAX));
        }
    }

    return dp[r][f];
    }
};