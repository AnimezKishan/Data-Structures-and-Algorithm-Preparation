/*Lets take example of test case,
s = 10010100
It's possible solutions are:-
    -> 10101010
    -> 01010101
Observe, one Alternating Binary String starts with zero and one that starts with one.
So, store the count of changes needed in original string for both alternating strings and return the minimum count.
*/

class Solution {
public:
    char alternate(char ch){
        if(ch == '0')
            return '1';
        else
            return '0';
    }
    int minOperations(string s) {
        char start_with_zero = '0';
        char start_with_one = '1';
        int SWZcount = 0, SWOcount = 0;

        for(int i=0;i<s.length();i++){
            if(s[i] != start_with_zero)
                SWZcount++;
            else if(s[i] != start_with_one)
                SWOcount++;
            
            start_with_zero = alternate(start_with_zero);
            start_with_one = alternate(start_with_one);
        }

        return min(SWZcount, SWOcount);
    }
};

/*
OBSERVATION:
changes needed to match alternating string that starts with one = n - changes needed to match alternating string that starts with zero
So, we actually dont need start_with_one as it can be:-
return min(SWZcount, (n-SWZcount));
*/