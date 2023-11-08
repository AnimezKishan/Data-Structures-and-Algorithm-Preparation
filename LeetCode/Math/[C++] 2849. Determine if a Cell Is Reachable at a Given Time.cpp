class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {

        //Edge Case
        if(fx == sx && fy == sy && t == 1)
            return false;
            
        int vert, hori;
        vert = abs(fx - sx);
        hori = abs(fy - sy);
        
        // max(vert, hori) --> Chebyshev distance (the max value represents that it would least that much moves even if you move diagonally all the time.)
        if(t >= max(vert, hori))
            return true;
        return false;
    }
};