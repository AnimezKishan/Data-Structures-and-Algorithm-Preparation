class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum1 = (n*(n+1))/2;

        // Sum of no.s that are divisible.
        // Sum of Arithemetic Progression, Sn = n/2 * [2a + (n - 1)d]
        int n1 = n/m;
        int sumDiv = (n1 * (2*m + (n1-1)*m))/2; 

        return (sum1 - sumDiv) - sumDiv;
    }
};