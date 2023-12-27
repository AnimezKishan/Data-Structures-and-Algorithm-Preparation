// Two - Pointer

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        int i=0;
        int j=i+1;
        int ans = 0;
        while(i<n-1 && j<n){
            if(colors[i] == colors[j]){
                int left = neededTime[i];
                int right = neededTime[j];
                if(left <= right){
                    ans += left;
                    i = j;
                    j++;
                }
                else{
                    ans += right;
                    j++;
                }
            }
            else{
                i = j;
                j++;
            }
        }

        return ans;
    }
};