class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;

        //find all prefixes for each number in arr1
        for(int &num : arr1) {
            while(!prefixes.count(num) && num){
                prefixes.insert(num);
                num /= 10;
            }
        }

        // search for longest common prefix
        int ans = 0;
        for(int &num : arr2) {
            while(!prefixes.count(num) && num)
                num /= 10;
            
            // it takes log10(num) + 1 to calculate no. of digits in a number (length)
            // static_cast is used to convert it to int
            if(num > 0) {
                ans = max(ans, static_cast<int>(log10(num) + 1));
            }
        } 

        return ans;
    }
};