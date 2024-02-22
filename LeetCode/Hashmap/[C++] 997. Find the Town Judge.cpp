class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustCount(n+1, 0), trustedBy(n+1, 0);

        for(vector<int> &t:trust){
            trustCount[t[0]]++;
            trustedBy[t[1]]++;
        }

        for(int i=1;i<=n;i++)
            if(trustCount[i] == 0 && trustedBy[i] == n-1)
                return i;
        
        return -1;
    }
};