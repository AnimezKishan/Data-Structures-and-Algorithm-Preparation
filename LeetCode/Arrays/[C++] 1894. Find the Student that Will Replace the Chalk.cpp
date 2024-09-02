class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long prefixSum = chalk[0];
        for(int i=1; i<n; i++) {
            prefixSum = prefixSum + chalk[i];
        }

        long long sum = 0;
        while(sum <= k){
            sum += prefixSum;
        }

        for(int i=n-1; i>=0; i--){
            sum -= chalk[i];
            if(sum <= k)
                return i;
        }

        return -1;
    }   
};