/* 
Heap can help in calculating subarray sums of an array.
we push all smallest possible subarrays into heap, and each try to expand itself.

O(n^2 * log(n)) 
    -> log(n) for heap push and pop 
    -> worst case is to calculate sum for all subarrays and we know (n * (n + 1) / 2) is the total possible subarrays. Therefore, ~ n^2 operations needed. 
*/
class Solution {
public:
    int MOD = 1e9 + 7;
    typedef pair<int, int> P;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // min heap to store the subarray sum in increasing order
        priority_queue<P, vector<P>, greater<P>> pq;

        // store smallest subarrays possible i.e. subarray with one element
        for(int i=0; i<n; i++)
            pq.push({nums[i], i}); // store the element and it's index number.

        int ans = 0;
        for(int count=1; count<=right; count++){
            int sum = pq.top().first;
            int idx = pq.top().second;
            pq.pop();

            if(count >= left)
                ans = (ans + sum) % MOD;

            // add current subarray sum with next element if available 
            int nextIdx = idx + 1;
            if(nextIdx < n){
                pq.push({(sum + nums[nextIdx])%MOD, nextIdx});
            }
        }

        return ans;
    }
};

// Brute Force
/*
class Solution {
public:
    int MOD = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> vec;
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                vec.push_back(sum);
            }
        }

        sort(begin(vec), end(vec));
        int ans = 0;
        for(int i=left-1; i<right; i++)
            ans = (ans + vec[i]%MOD)%MOD;

        return ans;
    }
};
*/