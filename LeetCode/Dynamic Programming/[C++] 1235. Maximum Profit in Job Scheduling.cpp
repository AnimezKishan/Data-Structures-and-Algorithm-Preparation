// Sorting (Lambda Function) + DP + Binary Search

class Solution {
public:
    int n;
    int dp[50001];
    int getNextIndex(vector<vector<int>> &arr, int s, int currentJobLast){
        int e = n-1;
        int result = n+1;

        while(s <= e){
            int mid = s + (e-s)/2;

            if(arr[mid][0] >= currentJobLast){
                result = mid;
                e = mid-1;
            }
            else
                s = mid+1;
        }

        return result;
    }

    int solve(int i, vector<vector<int>> &arr){
        if(i >= n)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int next = getNextIndex(arr, i+1, arr[i][1]);
        int take = arr[i][2] + solve(next, arr);
        int leave = solve(i+1, arr);

        return dp[i] = max(take, leave);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = profit.size();
        memset(dp, -1, sizeof(dp));
        vector<vector<int>> arr(n, vector<int>(3, 0));

        for(int i=0;i<n;i++){
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];
        }    

        auto comp = [&](auto &v1, auto &v2){
            return v1[0] <= v2[0];
        };

        sort(begin(arr), end(arr), comp);

        return solve(0, arr);
    }
};