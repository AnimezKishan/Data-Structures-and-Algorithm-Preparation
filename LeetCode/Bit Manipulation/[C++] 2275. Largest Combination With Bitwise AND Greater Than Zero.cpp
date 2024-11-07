class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        // The longest combination will be given by the numbers that have 1 on the same position.
        // Use an int[24] count to count the position of 1s of each number
        vector<int> countOnes(24, 0);

        for(int &candidate : candidates) {
            int i = 0;
            while(candidate) {
                countOnes[i++] += candidate & 1;
                candidate = candidate >> 1; 
            }
        }

        return *max_element(begin(countOnes), end(countOnes));
    }
};