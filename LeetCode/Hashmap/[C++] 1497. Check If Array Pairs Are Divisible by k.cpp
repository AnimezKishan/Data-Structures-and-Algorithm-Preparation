class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> remainderCount;
        
        // Calculate the remainder of each element mod k and count the occurrences
        for (int &num : arr) {
            int remainder = ((num % k) + k) % k;
            remainderCount[remainder]++;
        }
        
        for (auto &num : arr) {
            int remainder = ((num % k) + k) % k;

            // If the remainder is 0, we need an even number of such elements
            if (remainder == 0) {
                if (remainderCount[remainder] % 2 != 0) {
                    return false;
                }
            } 
            // If remainder is not 0, pair it with k - remainder
            else {
                int pairRemainder = k - remainder;
                if (remainderCount[remainder] != remainderCount[pairRemainder]) {
                    return false;
                }
            }
        }

        return true;
    }
};
