// Floyd's Cycle Detection
// The key is to understand how to treat the input array as a linked list.

/*
Take the array [1,3,4,2] as an example, the index of this array is [0,1,2,3], we can map the index to the nums[n].
0 → 1 → 3 → 2 → 4 → 3 → 2

If there are a repeated numbers in the array, take the array [1,3,4,2,2] as an example,

0 → 1 → 3 → 2 → 4 → 2 → 4 → 2 → 4 → 2 .......

Here 2 → 4 creates a cycle so we can apply fast slow approach here.
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;

        // Detect Cycle
        // since fast and slow are equal at start, so using do while.
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        // Now, find which element is causing cycle.
        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};


// Similar Solution to 442

/*
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int idx = abs(nums[i]);
            if(nums[idx] > 0)
                nums[idx] = -nums[idx];
            else
                return idx;
        }

        return -1;
    }
};
*/