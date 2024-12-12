class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq; // max-heap

        for(int &gift : gifts)
            pq.push(gift);

        while(k-- && !pq.empty()) {
            int n = pq.top();
            pq.pop();

            pq.push(floor(sqrt(n)));
        }

        long long ans = 0;
        while(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};