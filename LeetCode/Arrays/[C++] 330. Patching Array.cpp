// Greedy
/*
maxReach tells what is the max no. that can be made using current elements i.e [1, maxReach] elements can be formed.

If (maxReach + 1) < current indexed value (this means that some no./no.s smaller than current indexed value are getting left behind)
    So, include the just greater number than maxReach i.e. maxReach+1 (Greedy)
Else, 
    Include the current value and increase maxReach accordingly.
*/

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patch = 0, i = 0;
        long maxReach = 0;
        while(maxReach < n){
            if(i < nums.size() && (maxReach+1 >= nums[i])){
                maxReach += nums[i];
                i++;
            }
            else{
                maxReach += (maxReach+1);
                patch++;
            }
        }

        return patch;
    }
};