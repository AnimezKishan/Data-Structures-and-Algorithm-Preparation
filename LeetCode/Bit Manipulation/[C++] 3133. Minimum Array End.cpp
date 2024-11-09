class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;

        for(int i=1; i<n; i++) {
            // this way set bit of x remains set and unset bit becomes set with iterations.
            ans = (ans+1) | x;
        }

        return ans;
    }
};