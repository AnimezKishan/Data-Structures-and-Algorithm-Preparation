// Greedy + Heap

class Solution {
public:
    typedef pair<double, pair<int, int>> P;
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<P> pq; //max-heap
        int n = classes.size();

        for(int i=0; i<n; i++) {
            int studentPassed = classes[i][0];
            int totalStudents = classes[i][1];

            double incrementRatioDiff = (double)(studentPassed+1)/(totalStudents+1) - (double)studentPassed/totalStudents;
            pq.push({incrementRatioDiff, {studentPassed, totalStudents}});
        }

        while(!pq.empty() && extraStudents--) {
            auto tp = pq.top();
            pq.pop();

            int newPassed = tp.second.first + 1;
            int newTotal = tp.second.second + 1;
            double newDiff = (double)(newPassed+1)/(newTotal+1) - (double)newPassed/newTotal;

            pq.push({newDiff, {newPassed, newTotal}});
        }

        double sum = 0;
        while(!pq.empty()) {
            sum += (double)pq.top().second.first/pq.top().second.second;
            pq.pop();
        }

        return (double)(sum/n);
    }
};