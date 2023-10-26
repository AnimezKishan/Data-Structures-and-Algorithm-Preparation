class Solution {
public:
    int MOD = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int, long long> m;
        sort(begin(arr), end(arr));

        m[arr[0]] = 1;

        for(int i=1;i<arr.size();i++){
            m[arr[i]] = 1;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j] == 0 && m.find(arr[i]/arr[j]) != m.end())   
                {
                    m[arr[i]] += m[arr[j]] * m[arr[i]/arr[j]];
                }
            }
        }

        long ans = 0;
        for(auto i:m)   
        {
            cout<<i.second<<" ";
            ans = (ans + i.second) % MOD;
        }
        
        return ans;
    }
};