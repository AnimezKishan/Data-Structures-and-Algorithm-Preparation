class Solution {
public:
    typedef pair<long long, int> P;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(begin(meetings), end(meetings));
        vector<int> track(n, 0);

        priority_queue<int, vector<int>, greater<int>> availableRooms;
        priority_queue<P, vector<P>, greater<P>> usedRooms;

        for(int i=0;i<n;i++){
            availableRooms.push(i);
        }

        for(int i=0;i<meetings.size();i++){
            int start = meetings[i][0];
            int end = meetings[i][1];
            int duration = end - start;

            // if a room will be available before start time of meeting
            while(!usedRooms.empty() && usedRooms.top().first <= start){
                availableRooms.push(usedRooms.top().second);
                usedRooms.pop();
            }

            // when room is not assigned to any meeting yet.
            if(!availableRooms.empty()){
                usedRooms.push({end, availableRooms.top()});
                track[availableRooms.top()]++;
                availableRooms.pop();
            }
            
            // if all rooms are occupied, assign the meeting to the room which will be available earliest.
            else{
                auto temp = usedRooms.top();
                usedRooms.pop();
                usedRooms.push({temp.first + duration, temp.second});
                track[temp.second]++;
            }
        }

        int maxi = INT_MIN;
        int ans;
        for(int i=0;i<n;i++){
            if(track[i] > maxi){
                maxi = track[i];
                ans = i;
            }
        }

        return ans;
    }
};


// Brute Force
/*
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        sort(begin(meetings), end(meetings));

        vector<long long> availableAt(n, 0);
        vector<int> track(n, 0);

        for(int i=0;i<m;i++){
            long long currMin = LLONG_MAX;
            int currRoom;
            bool found = false;

            for(int j=0;j<n;j++){
                // if a room will be available before start time of meeting or when room is not assigned to any meeting yet.
                if(availableAt[j] <= meetings[i][0]){
                    availableAt[j] = meetings[i][1];
                    track[j]++;
                    found = true;
                    break;
                }

                if(availableAt[j] < currMin){
                    currMin = availableAt[j];
                    currRoom = j;
                }
            }

            // if all rooms are occupied, assign the meeting to the room which will be available earliest.
            if(!found){
                availableAt[currRoom] += meetings[i][1] - meetings[i][0];
                track[currRoom]++;
            }
        }

        int maxi = INT_MIN;
        int ans;
        for(int i=0;i<n;i++){
            if(track[i] > maxi){
                maxi = track[i];
                ans = i;
            }
        }

        return ans;
    }
};
*/