class Solution {
    public:
        int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
            int n = arr.size();
    
            int ans = 0;
            for(int i=0; i<=n-3; i++) {
                for(int j=i+1; j<=n-2; j++) {
                    for(int k=j+1; k<n; k++) {
                        int c1 = abs(arr[i] - arr[j]);
                        int c2 = abs(arr[j] - arr[k]);
                        int c3 = abs(arr[i] - arr[k]);
    
                        if(c1 <= a && c2 <= b && c3 <= c)
                            ans++;
                    }
                }
            }
    
            return ans;
        }
    };