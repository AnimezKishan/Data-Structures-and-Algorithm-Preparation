class Solution {
public:
    int M = 1e9+7;
    int countOrders(int n) {
        if(n == 1)
            return 1;

        long long result = 1;
        for(int i=2;i<=n;i++)
        {
            //no. of spaces available to place pickup(i) and delivery(i)
            int spaces = i*2 - 1;

            //no. of possibility = first natural no. sum till spaces.
            //no. of possibility for each result of previous order = result * no. of possibility
            result *= spaces*(spaces+1)/2;

            //to keep ans in range
            result %= M;
        }
        return result;
    }
};