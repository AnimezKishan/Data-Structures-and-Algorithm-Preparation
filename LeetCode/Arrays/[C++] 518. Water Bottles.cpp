// Simulation

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int initialBottles = numBottles;
        while(numBottles >= numExchange){
            ans += numBottles / numExchange;
            int consumedBottles = numBottles / numExchange;
            int leftBottles = numBottles % numExchange;

            numBottles = consumedBottles + leftBottles;
        }

        ans += initialBottles;
        return ans;
    }
};