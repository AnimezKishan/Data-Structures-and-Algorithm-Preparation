/*
-> Build a min heap 
-> Get first two minimum elements, pop them, store their sum in right place inside min heap.
*/

/*
T.C -> O(nlog(n))
S.C -> O(n)
*/
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long, vector<long long>, greater<long long>> min_heap;
        for(int i=0;i<n;i++)
        {
            min_heap.push(arr[i]);
        }
        
        long long ans = 0;
        while(min_heap.size() > 1)
        {
            long long a = min_heap.top();
            min_heap.pop();
            
            long long b = min_heap.top();
            min_heap.pop();
            
            ans += a+b;
            min_heap.push(a+b);
        }
        return ans;
    }
};