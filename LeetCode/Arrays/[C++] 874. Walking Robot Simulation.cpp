class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> obs;
        for(vector<int> &o : obstacles){
            obs.insert(to_string(o[0]) + "_" + to_string(o[1]));
        }

        int idx = 0, currX = 0, currY = 0, ans = 0;
        for(int &command : commands) {
            if(command == -1){
                idx++;
                if(idx > 3)
                    idx = 0;
                continue;
            }
            else if(command == -2) {
                idx--;
                if(idx < 0)
                    idx = 3;
                continue;
            }

            int val = command;
            while(val--) {
                int newX = currX + directions[idx][0];
                int newY = currY + directions[idx][1];

                if(obs.find(to_string(newX) + "_" + to_string(newY)) == obs.end()){
                    currX = newX;
                    currY = newY;
                }
                else
                    break;
            }

            ans = max(ans, currX*currX + currY*currY);
        }
        return ans;
    }
};