//Bits Manipulation

class Solution {
public:
    char findTheDifference(string s, string t) {
        s += t;

        int ans = 0;
        for(char &i: s)
            ans^=i;
        
        return ans;
    }
};


//ASCII 

/*
class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum1 = 0, sum2 = 0;
        
        for(auto &i:s)
            sum1 += i;
        
        for(auto &i:t)
            sum2 += i;
        
        int ans = abs(sum2-sum1);
        return char(ans);
    }
};
*/