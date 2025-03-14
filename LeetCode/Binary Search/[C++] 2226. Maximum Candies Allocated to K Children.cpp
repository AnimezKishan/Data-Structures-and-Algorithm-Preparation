class Solution {
    public:
        bool isPoss(vector<int>& candies, long long k, int mid) {
            long long childs = 0;
            for(int &candy : candies) {
                if(childs == k)
                    return true;
                
                if(candy/mid) {
                    childs += candy/mid;
                }
            }
    
            return childs >= k;
        }
        int maximumCandies(vector<int>& candies, long long k) {
            int n = candies.size();
    
            int s = 1, e = INT_MIN;
            for(int i=0; i<n; i++)
                e = max(e, candies[i]);
    
            int ans = 0;
            while(s <= e) {
                int mid = s + (e-s)/2;
                if(isPoss(candies, k, mid)) {
                    ans = mid;
                    s = mid + 1;
                }
                else
                    e = mid - 1;
            }
    
            return ans;
        }
    };