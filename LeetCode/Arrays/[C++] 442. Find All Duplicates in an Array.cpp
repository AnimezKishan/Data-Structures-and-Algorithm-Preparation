/*
Think in terms of on and off. Turning on and turning off a switch. If a switch is already turned on, you can not turn it on again.
Here, if a number turns out to be negative, then it must be visited earlier.
Given this: [2,5,2,1,1,4]

Go to index 0 and flip whatever value index 0 pointing to[if it was not flipped(turned on) before]...

What does that mean?

Index 0 has value 2. Flip whatever 2 is pointing-to. Since the array is 0 based, so we will flip 2-1 = 1 and that is 5.

So, our result will look like:[2,-5,2,1,1,4]

Next, we will go to index 1. After modifying the array, value at index 1 might or might not become negative. So, for this, we get the absolute value of that position. So, flip(if it was not flipped before) whatever abs(arr[1])-1 = 4 pointing to.

Since 4 is pointing to 1 and it is not negative(not flipped before), so we flip it to -1.

[2,-5,2,1,-1,4]

Next index 2, value 2, and it is pointing -5, which must be flipped by some other 2  
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        for(int i=0;i<nums.size();i++){0.
            int num = abs(nums[i]);
            int idx = num - 1;
            if(nums[idx] > 0)
                nums[idx] = - nums[idx];
            else
                ans.push_back(abs(num));
        }

        return ans;
    }
};