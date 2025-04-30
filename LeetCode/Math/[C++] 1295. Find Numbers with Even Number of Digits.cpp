// Approach I
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int &num : nums) {
            int count = 0;
            while(num) {
                count++;
                num /= 10;
            }

            if(count % 2 == 0)
                ans++;
        }

        return ans;
    }
};


// Approach II
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int &num : nums) {
            int digit = floor(log10(num)) + 1;
            if(digit % 2 == 0)
                ans++;
        }

        return ans;
    }
};