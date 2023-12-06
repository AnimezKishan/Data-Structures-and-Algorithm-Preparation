/*
If n teams are playing, 
    -> 1 becomes winner in last.
    -> n-1 teams get eliminated.

And, To eliminate n-1 teams, n-1 matches should be played.
*/

class Solution {
public:
    int numberOfMatches(int n) {
        return n-1;
    }
};


//Brute Force
/*
class Solution {
public:
    int numberOfMatches(int n) {
        int ans = 0;
        while(n>1){
            if(n&1){
                ans += (n-1)/2;
                n = ((n-1)/2)+1;
            }
            else{
                ans += n/2;
                n /= 2;
            }
        }

        return ans;
    }
};
*/