class Solution {
public:
    typedef pair<int, int> P;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool isSafe(int i, int j, int m, int n) {
        if(i >= 0 && i < m && j>=0 && j < n)
            return true;
        return false;
    }
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(), n = moveTime[0].size();

        priority_queue<pair<int, P>, vector<pair<int, P>>, greater<pair<int, P>>> pq; // min-heap
        vector<vector<int>> minTime(m, vector<int>(n, INT_MAX));
        pq.push({0, {0, 0}});

        while(!pq.empty()) {
            int time = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            if(i == m-1 && j == n-1)
                return minTime[m-1][n-1];

            for(vector<int> dir : dirs) {
                int newI = i + dir[0];
                int newJ = j + dir[1];

                if(isSafe(newI, newJ, m, n)) {
                    int newTime;
                    if(time < moveTime[newI][newJ]) {
                        newTime = moveTime[newI][newJ] + 1;
                    } else {
                        newTime = time + 1;
                    }

                    newTime += (i + j) % 2;

                    if(newTime < minTime[newI][newJ]) {
                        minTime[newI][newJ] = newTime;
                        pq.push({newTime, {newI, newJ}});
                    }
                }
            }
        }

        return minTime[m-1][n-1];
    }
};