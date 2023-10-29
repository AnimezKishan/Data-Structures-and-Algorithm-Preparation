class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int noOfTrails = minutesToTest/minutesToDie;

        int pigs = 0;
        while(pow(noOfTrails+1, pigs) < buckets)
            pigs++;
        
        return pigs;
    }
};