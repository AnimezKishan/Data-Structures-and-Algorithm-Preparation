class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        if(n == 1)
            return 0;
        
        vector<int> camSum(n, 0);
        for(int i=0;i<n;i++){
            for(char &ch:bank[i]){
                if(ch == '1')
                    camSum[i]++;
            }
        }

        int i = 0, j = 1, ans = 0;
        while(i < n-1 && j < n){
            if(camSum[j] == 0)
                j++;
            else{
                ans += (camSum[i]*camSum[j]);
                i = j;
                j++;
            }
        }

        return ans;
    }
};