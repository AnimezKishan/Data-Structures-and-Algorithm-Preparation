class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // Sort the intervals based on the start time
        sort(begin(intervals), end(intervals));
        // Min Heap to track the end times of the groups
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto &interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            
            // If the current start is greater than or equal to the smallest end in the queue, we can extend the current group
            if (!pq.empty() && pq.top() < start) {
                pq.pop();
            }

            // Push the current interval (either new group or extended group)
            pq.push(end);
        }

        return pq.size();
    }
};
