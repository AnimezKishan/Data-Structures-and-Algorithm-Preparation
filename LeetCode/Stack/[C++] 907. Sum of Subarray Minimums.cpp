// Next Smaller Element's Index + Prev Smaller Element's Index
// Similar to largest rectangle in the histogram

typedef unsigned long long ll;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> prevSmaller(n), nextSmaller(n);

        stack<int> st1;
        for(int i=0;i<n;i++){
            while(!st1.empty() && arr[i] < arr[st1.top()])
                st1.pop();
            
            if(st1.empty()){
                st1.push(i);
                prevSmaller[i] = -1;
            }
            else{
                prevSmaller[i] = st1.top();
                st1.push(i);
            }
        }

        while(!st1.empty())
            st1.pop();
        
        for(int i=n-1;i>=0;i--){
            while(!st1.empty() && arr[i] <= arr[st1.top()])
                st1.pop();
            
            if(st1.empty()){
                st1.push(i);
                nextSmaller[i] = n;
            }
            else{
                nextSmaller[i] = st1.top();
                st1.push(i);
            }
        }

        ll ans = 0;
        int M = 1e9 + 7;
        for(int i=0;i<n;i++){
            int prevSmallerIndex = i - prevSmaller[i];
            int nextSmallerIndex = nextSmaller[i] - i;

            ll two_ways = prevSmallerIndex * nextSmallerIndex;
            ll sum_two_ways = two_ways * arr[i];
            ans = (ans + sum_two_ways)%M;
        }
        
        return ans;

    }
};