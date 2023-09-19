/*
Fast Slow Approach (Two Pointer)
The key is to understand how to treat the input array as a linked list.

Take the array [1,3,4,2] as an example, the index of this array is [0,1,2,3], we can map the index to the nums[n].
0 → 1 → 3 → 2 → 4 → 3 → 2

If there are a repeated numbers in the array, take the array [1,3,4,2,2] as an example,

0 → 1 → 3 → 2 → 4 → 3 → 2 → 4 → 2 → 4 → 2 .......

Here 2 → 4 creates a cycle so we can apply fast slow approach here.
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        slow = 0;
        do{
            slow = nums[slow];
            fast = nums[fast];
        }while(slow != fast);

        return slow;
    }
};