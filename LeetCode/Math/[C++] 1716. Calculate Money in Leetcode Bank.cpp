// A.P
/*
Suppose, n=21

(1 + 2 + 3 + 4 + 5 + 6 + 7) = 28
(2 + 3 + 4 + 5 + 6 + 7 + 8) = 35
(3 + 4 + 5 + 6 + 7 + 8 + 9) = 42

A.P = 28, 35, 42,....
Here, Common Difference = 7 and a (first term) = 28
*/

class Solution {
public:
    int totalMoney(int n) {
        int first_term = 28;
        int terms = n/7;
        int last_term = first_term + (terms-1)*7;

        //Sum of n A.P Terms
        int ans = terms * (first_term + last_term)/2;

        //if n is not perfectly divisible by 7, it has some remaining days.
        int remaining_start_money = 1 + terms;
        for(int i =1;i<=(n%7);i++)
            ans += remaining_start_money++;
        
        return ans;
    }
};