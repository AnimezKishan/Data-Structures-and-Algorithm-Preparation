/*
Store the start times and end times in separate containers in sorted way.
Iterate for each people's arrival time/day
    -> Upper bound for start time represents how many flowers we can have if we get a flower of each progressive iteration.
    -> Lower bound for end time represents no. of flowers need to be deducted as they only start to grow from the spefied day.
*/

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> startTimes, endTimes;

        for(int i=0;i<flowers.size();i++)
        {
            startTimes.push_back(flowers[i][0]);
            endTimes.push_back(flowers[i][1]);
        }

        sort(begin(startTimes), end(startTimes));
        sort(begin(endTimes), end(endTimes));

        vector<int> ans;
        for(int i=0;i<people.size();i++){
            ans.push_back((upper_bound(begin(startTimes), end(startTimes), people[i]) - begin(startTimes)) - (lower_bound(begin(endTimes), end(endTimes), people[i]) - begin(endTimes)));
        }

        return ans;
    }
};