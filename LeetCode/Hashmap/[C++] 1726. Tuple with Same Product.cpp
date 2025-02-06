class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long int, int> products;

        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                long int product = nums[i] * nums[j];
                if(products.find(product) != products.end())
                    ans += products[product] * 8;
                
                products[product]++;
            }
        }

        return ans;
    }
};