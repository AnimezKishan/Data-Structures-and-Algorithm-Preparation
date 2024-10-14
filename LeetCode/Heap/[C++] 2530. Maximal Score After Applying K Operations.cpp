class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> pq;
        for(int &num : nums)
            pq.push(num);
        
        while(k-- && !pq.empty()) {
            int curr = pq.top();
            pq.pop();
            ans += curr;
            // Note:  int/int is still an int
            // double newVal = double(curr) / double(3);
            // pq.push(ceil(newVal));

            // It's not necessary to use ceil function. It's slow and gives wrong results for large integers because of floating point precision loss. Ceiling division may be performed like (n + 2) / 3 instead.
            pq.push((curr+2)/3);
        }

        return ans;
    }
};