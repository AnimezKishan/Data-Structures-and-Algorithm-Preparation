// Math
// T.C -> O(sqrt(c * log(c))) [sqrt(c) as a goes till sqrt(c) and log(c) to calculate b for every iteration]
// S.C -> O(1)

class Solution {
public:
    bool judgeSquareSum(int c) {
        for(double a=0; a*a<=c; a++){
            double b = sqrt(c - (a*a));

            if(b == (int)b)
                return true;
        }

        return false;
    }
};

//Two - Pointer
// T.C -> O(sqrt(c))
// S.C -> O(1)
/*
class Solution {
public:
    bool judgeSquareSum(int c) {
        long a = 0;
        long b = sqrt(c);

        while(a <= b){
            long k = (a*a) + (b*b);

            if(k > c)
                b--;
            else if(k < c)
                a++;
            else
                return true;
        }

        return false;
    }
};
*/