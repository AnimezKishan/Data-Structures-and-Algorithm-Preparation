class Solution {
public:
    int n;
    int dp1[100001][3];
    int dp2[100001][3];
    int solve_inc(vector<int>&rating,int i,int count){
        if(count==2) 
            return 1;
        if(i>=n) 
            return 0;
            
        if(dp1[i][count]!=-1) 
            return dp1[i][count];

        int ans=0;

        for(int j=i+1;j<n;j++){
            if(rating[j]>rating[i]){
                ans+=solve_inc(rating, j, count+1);
            }
        }
        return dp1[i][count]=ans;
    }
    int solve_dec(vector<int>&rating,int i,int count){
        if(count==2) 
            return 1;
        if(i>=n) 
            return 0;

        if(dp2[i][count]!=-1) 
            return dp2[i][count];

        int ans=0;

        for(int j=i+1;j<n;j++){
            if(rating[j]<rating[i]){
                ans+=solve_dec(rating, j, count+1);
            }
        }
        return dp2[i][count]=ans;
    }
    int numTeams(vector<int>& rating) {
        memset(dp1,-1,sizeof(dp1));
        memset(dp2,-1,sizeof(dp2));
        n=rating.size();

        int ans=0;
        for(int i=0;i<n;i++){
            ans+=solve_inc(rating,i,0) + solve_dec(rating,i,0);
        }

        return ans;
    }
};