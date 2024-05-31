/*
-> XOR all numbers
-> Find rightmost set and make a mask out of it.
-> now, do num & mask and store in two separate groups
-> At end, you'll left with 1 no. in each group as other no.s will cancel out each other.

Example ->
[1, 2, 1, 3, 2, 5]

XOR of all 1^1^2^2^3^5 = 6
As others cancel out each other. Now observe,
3 -> 011
5 -> 101
---------
6 -> 110

Rightmost set bit of 6, here it is 1st bit that indicates the 1st bit of two no.s with one occurance
must have there 1st bit different to each other.

So, we can form two groups for each as others will cancel out each other in group.

Now, to find rightmost set bit.
    -> Conventional Method :- rightshift n i.e. 6 here each time and check if rightmost bit is 
       set or not (using n&1 == true). Also, store the count. And make a mask 
       according to the count (leftshift 1 count no. of times).
    
    -> Method 2 :- n & (-n) [two's complement of two] also gives a mask w.r.t rightmost set bit.
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long XOR = 0;

        for(int &n : nums)
            XOR ^= n;

        int mask = XOR & (-XOR);

        int group1 = 0, group2 = 0;
        for(int &n : nums) {
            if(n & mask)
                group1 ^= n;
            else
                group2 ^= n;
        }

        return { group1, group2 };
    }
};