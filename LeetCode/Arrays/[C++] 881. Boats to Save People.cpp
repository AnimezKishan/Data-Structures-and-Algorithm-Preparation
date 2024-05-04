// Greedy + Sorting + Two Pointer

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people), end(people));
        int ans = 0, n = people.size();
        int i = 0, j = n-1;

        while(i<=j){
            if(i == j){
                ans++;
                return ans;
            }
            if(people[i] + people[j] <= limit){
                j--;
                i++;
                ans++;
            }
            else{
                j--;
                ans++;
            }
        }

        return ans;
    }
};