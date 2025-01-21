class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstRowRemainingSum = accumulate(begin(grid[0]), end(grid[0]), 0LL);

        long long secondRowRemainingSum = 0;

        long long minimisedRobot2Sum = LONG_LONG_MAX;

        for(int robot1Col = 0; robot1Col<grid[0].size(); robot1Col++) {
            firstRowRemainingSum -= grid[0][robot1Col];

            long long bestOfRobot2 = max(firstRowRemainingSum, secondRowRemainingSum);

            minimisedRobot2Sum = min(minimisedRobot2Sum, bestOfRobot2);

            secondRowRemainingSum += grid[1][robot1Col];
        }
        
        return minimisedRobot2Sum;
    }
};