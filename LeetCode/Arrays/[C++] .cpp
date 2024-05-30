class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> prefixXOR(begin(arr), end(arr));
        prefixXOR.insert(prefixXOR.begin(), 0); // initially the xor cumulative will be 0
        int n = prefixXOR.size();

        for(int i=1; i<n; i++)
            prefixXOR[i] ^= prefixXOR[i-1];

        int ans = 0;

        for(int i=0; i<n; i++){
            for(int k=i+1; k<n; k++){
                if(prefixXOR[i] == prefixXOR[k])
                    // Similar to concept of cummulative sum(prefix sum) + map
                    /* if current xor value of prefix array is seen previously at index y, 
                    then length of subarray(x) = (current index - y), must satisfy the conditions.
                    And add x-1 to the answer as (x-1) combinations are possible.
                    */
                    ans += (k - i - 1);
            }
        }

        return ans;
    }
};