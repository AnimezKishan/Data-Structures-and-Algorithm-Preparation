class Solution {
    public:
        typedef long long ll;
        int minOperations(vector<int>& nums, int k) {
            priority_queue<ll, vector<ll>, greater<ll>> pq; // min-heap
    
            for(int &num : nums)
                pq.push(num);
    
            int ans = 0;
            while(pq.top() < k) {
                ll first = pq.top(); 
                pq.pop();
                ll second = pq.top(); 
                pq.pop();
    
                ll newNum = (ll(min(first, second)) * 2) + ll(max(first, second));
                pq.push(newNum);
                ans++;
            }
    
            return ans;
        }
    };
    