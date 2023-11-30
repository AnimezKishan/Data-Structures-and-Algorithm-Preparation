class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n == 0)
            return 0;

        vector<long long> F(31, 1);

        for(int i=1;i<31;i++)
            F[i] = (2 * F[i-1]) + 1; 

        int swap = 1;
        int ans = 0;
        for(int i = 30;i>=0;i--)
        {
            int ith_bit = ((1 << i) & n);
            if(ith_bit == 0)
                continue;
            
            if(swap > 0)
                ans += F[i];
            else
                ans -= F[i];
            
            swap *= -1;
        }

        return ans;

    }
};