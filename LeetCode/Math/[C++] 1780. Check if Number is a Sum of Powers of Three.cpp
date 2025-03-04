//  convert the number to base 3 (like you do while converting decimal to binary) and check the digits (it should be 0 or 1 only).
class Solution {
public: 
    bool checkPowersOfThree(int n) {
        int rem = 0;

        while(n) {
            rem = n % 3;
            if(rem == 2)
                return false;
            n /= 3;
        }

        return true;
    }
};

// Recursive Solution
/*
class Solution {
    public: 
    bool solve(int exp, int currSum, int &n) {
        if(currSum > n)
            return false;
        
        if(currSum == n)
            return true;
        
        if(exp < 0)
            return false;

        bool take = false, not_take = false;
        take = take || solve(exp-1, currSum + pow(3, exp), n);
        if(take)
            return true;
        not_take = not_take || solve(exp - 1, currSum, n);
        if(not_take)
            return true;
        
        return false;
    }
    bool checkPowersOfThree(int n) {
        return solve(16, 0, n);
    }
};
*/