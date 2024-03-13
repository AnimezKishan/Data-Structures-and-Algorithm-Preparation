class Solution {
public:
    int pivotInteger(int n) {
        for(int x=1;x<=n;x++){
            // sum of natural no.s till 'x'.
            float frontSum = (x*(x+1))/2;

            // sum of natural no.s till 'n' - sum of natural no.s till 'x-1'
            float backSum = ((n*(n+1))/2) - ((x*(x-1))/2);

            if(frontSum == backSum)
                return x;
        }

        return -1;
    }
};