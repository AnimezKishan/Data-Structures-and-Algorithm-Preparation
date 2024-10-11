// Sorting + Min Heap

class Solution {
public:
    typedef pair<int, int> P;
    int smallestChair(vector<vector<int>>& times, int targetFriend) {

        // Convert the given times into a vector of pairs, where each pair represents the arrival and leaving time of a friend, and the index of the friend in the original times vector.
        vector<pair<P, int>> timesIdx;
        for(int i=0; i<times.size(); i++){
            timesIdx.push_back({{times[i][0], times[i][1]}, i});
        }

        auto lambda = [&](pair<P, int> &a, pair<P, int> &b) {
            return a.first.first < b.first.first;
        };

        // Sort according to the arrival time
        sort(begin(timesIdx), end(timesIdx), lambda);

        // Use two min-heaps, one for storing the leaving times that have already been processed, and one for storing the chairs that are currently unoccupied.
        priority_queue<P, vector<P>, greater<P>> leavingToOccupied;
        priority_queue<int, vector<int>, greater<int>> unoccupied;
        int i = 0, n = timesIdx.size();
        for(int i=0; i<n; i++)
            unoccupied.push(i);

        while(i < n) {
            // for current starting time, change seats from occupied to unoccupied for ending time of arrived friends less than starting time.
            while(!leavingToOccupied.empty() && leavingToOccupied.top().first <= timesIdx[i].first.first){
                unoccupied.push(leavingToOccupied.top().second);
                leavingToOccupied.pop();
            }
            
            // targetFriend found
            if(timesIdx[i].second == targetFriend)
                return unoccupied.top();
            
            // else, assign the current arrived friend's leaving time and assign min available occupied seat.
            leavingToOccupied.push({timesIdx[i].first.second, unoccupied.top()});
            unoccupied.pop();
            i++;
        }

        return -1;
    }
};