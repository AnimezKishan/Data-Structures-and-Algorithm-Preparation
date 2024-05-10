class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<double, pair<int, int>>> pq;

        // Firstly, Push only fractions formed from dividing with largest element
        for(int i=0;i<n;i++)
            pq.push({(-1.0 * arr[i]/arr[n-1]), {i, n-1}});
        
        // Iteratively remove the top element (smallest fraction) and replace it with the next smallest fraction
        while(k > 1){
            pair<int, int> currIdx = pq.top().second;

            pq.pop();

            pq.push({(-1.0 * arr[currIdx.first]/arr[currIdx.second-1]), {currIdx.first, currIdx.second-1}}); 

            k--;
        }

        return { arr[pq.top().second.first], arr[pq.top().second.second] };
    }
};