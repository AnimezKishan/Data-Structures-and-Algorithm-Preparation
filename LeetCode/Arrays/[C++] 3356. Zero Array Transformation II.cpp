// Difference Array + Binary Search

class Solution {
    public:
        int n, Q;
        bool checkWithDifferenceArray(vector<int> &nums, vector<vector<int>>& queries, int k) {
            vector<int> diff(n, 0);
    
            for(int i=0; i<=k; i++) {
                int l = queries[i][0];
                int r = queries[i][1];
                int val = queries[i][2];
    
                diff[l] += val;
                if(r+1 < n)
                    diff[r+1] -= val;
            }
    
            int cumSum = 0;
            for(int i=0; i<n; i++) {
                cumSum += diff[i];
    
                diff[i] = cumSum;
    
                if(nums[i] > diff[i])
                    return false;
            } 
    
            return true;
        }
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            n = nums.size();
            Q = queries.size();
    
            auto lambda = [&](int x) {
                return x == 0;
            };
    
            if(all_of(begin(nums), end(nums), lambda)) {
                return 0; // no query req. as all array elements are already zero
            }
    
            int s = 0, e = Q-1;
            int ans = -1;
            while(s <= e) {
                int mid = s + (e - s)/2;
                if(checkWithDifferenceArray(nums, queries, mid)) {
                    ans = mid + 1; // mid + 1 as we need the count of queries
                    e = mid - 1; 
                }
                else
                    s = mid + 1;
            }
    
            return ans;
        }
    };