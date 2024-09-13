class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefixXor(n, arr[0]);

        for(int i=1; i<n ;i++) {
            prefixXor[i] = arr[i] ^ prefixXor[i-1]; 
        }

        vector<int> ans;
        for(vector<int> &query : queries) {
            int leftIdx = query[0];
            int rightIdx = query[1];

            if(leftIdx == 0)
                ans.push_back(prefixXor[rightIdx]);
            else
                ans.push_back(prefixXor[rightIdx] ^ prefixXor[leftIdx - 1]);
        }
        return ans;
    }
};