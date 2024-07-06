class Solution {
public:
    int passThePillow(int n, int time) {
        /* 
        n-1 iterations to cover a full round 
        example, n = 4
        1->2->3->4 => no. of iterations is 3 to cover a round.
        */

        // No. of full rounds in given time
        int fullRounds = time / (n-1);
        // some leftovers after full rounds
        int leftOver = time % (n-1);

        // if rounds are even means currPerson is in starting position, else is in ending position. Now, just deal with leftovers.
        if(fullRounds%2 == 0)
            return leftOver+1;
        else
            return n - leftOver;
    }
};


// Simulation
/*
class Solution {
public:
    int passThePillow(int n, int time) {
        int currPerson = 1;
        int dir = 1;
        while(time){
            if(currPerson+dir >= 1 && currPerson+dir <= n){
                currPerson += dir;
                time--;
            }
            else
                dir = -dir; 
        }

        return currPerson;
    }
};
*/