/*
The best way to do this is to think that as all the numbers are unique and we know the size of array, so we know all elements in the array. so, we know that in the sorted array arr[i] = i, it means that if we compute a running sum of elements in the array, then if at any moment, the sum = i*(i+1)/2, then we should make a partition at that point. continuing this process will give us the max no. of partitions.
like : 1, 0, 2, 3, 4
running sum : 1, 1, 3, 6, 10
i*(i+1)/2 : 0, 1, 3, 6, 10
for this, sum = i*(i+1)/2 condition is correct 4 times, so answer is 4
*/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int preSum = 0, n = arr.size();

        int ans = 0;
        for(int i=0; i<n; i++){
            preSum += arr[i];
            if(preSum == i*(i+1)/2)
                ans++;
        }

        return ans;
    }
};