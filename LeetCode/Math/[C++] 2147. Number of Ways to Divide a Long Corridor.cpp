class Solution {
public:
    int MOD = 1e9 + 7;
    int numberOfWays(string corridor) {
        vector<int> seatOccurance;

        for(int i=0;i<corridor.length();i++){
            if(corridor[i] == 'S')
                seatOccurance.push_back(i);
        }

        if(seatOccurance.size() % 2 != 0 || seatOccurance.size() == 0)
            return 0;

        long long ans = 1;
        for(int i=2;i<seatOccurance.size();){
            // no. of ways can be extracted from : ( first occurance of current seat pair - last occurance of previous seat pair ) 
            ans = (ans * (seatOccurance[i] - seatOccurance[i-1])) % MOD;
            i += 2;
        }

        return ans;
    }
};