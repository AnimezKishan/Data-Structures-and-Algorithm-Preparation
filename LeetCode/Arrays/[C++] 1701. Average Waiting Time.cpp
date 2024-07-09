// Simulation

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int currTime = customers[0][0];
        double totalWait = 0;

        for(vector<int> &customer : customers){
            // whether the current customer has already arrived or yet to come.
            currTime = max(currTime, customer[0]);

            // cooking time
            currTime += customer[1];

            // after cooking, how much time customer had to wait. 
            totalWait += currTime - customer[0];
        }

        return double(totalWait / customers.size());
    }
};