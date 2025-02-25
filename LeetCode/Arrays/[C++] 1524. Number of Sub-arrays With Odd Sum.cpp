/*
question is same as
https://leetcode.com/problems/subarray-sums-divisible-by-k/
just modify the k value to be 2 and condition as not divisible by K
*/
class Solution {
    public:
        int numOfSubarrays(vector<int>& arr) {
            int n = arr.size();
            int MOD = 1e9 + 7;
            int k = 2;
            long long int temp = (1LL * n * (n+1))/2;
            unordered_map<int, int> m;
            m[0] = 1;
    
            int sum = 0, divisibleSubarray = 0;
            for(int i=0; i<n; i++){
                sum += arr[i];
                int remainder = sum%k;
    
                if(m.find(remainder) != m.end())
                    divisibleSubarray = (divisibleSubarray + m[remainder]) % MOD;
    
                m[remainder]++;
            }
            // cout<<temp<<" "<<divisibleSubarray;
            return (temp - divisibleSubarray) % MOD;
        }
    };