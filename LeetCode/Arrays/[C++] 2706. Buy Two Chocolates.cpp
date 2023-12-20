class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int smallest = INT_MAX, second_smallest = 0;

        for(int i=0;i<prices.size();i++){
            if(prices[i] <= smallest){
                second_smallest = smallest;
                smallest = prices[i];
            }
            else if(prices[i] < second_smallest)
                second_smallest = prices[i];
            
        }

        int leftOver = money - (smallest + second_smallest);

        return leftOver < 0 ? money : leftOver;
    }
};