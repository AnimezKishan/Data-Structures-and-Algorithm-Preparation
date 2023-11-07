// Greedy + Sorting 
// Kill that monster first which takes least time to reach the city.

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> time(dist.size());
        for(int i=0;i<dist.size();i++)
            // ceil is used to make it take time at least of 1.
            time[i] = ceil((float)dist[i]/speed[i]);

        sort(begin(time), end(time));

        int ans = 1;
        int time_passed = 1;
        for(int i=1;i<time.size();i++)
        {
            if(time[i] - time_passed <= 0)
                return ans;
            
            ans++;
            time_passed++;
        }

        return ans;
    }
};