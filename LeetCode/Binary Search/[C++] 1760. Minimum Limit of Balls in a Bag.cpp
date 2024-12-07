/*
To find no of operations required to divide A such that max balls in each bag is X.
Say we want to divide 9 such that the max is 5, then to find the no of operations required.
The number of bags reqd :
ceil[9/5] = 2.
To create 2 bags we need 2-1 = 1 operations.

Now say we want to divide 9 such that the max is 3,
No of bags reqd
ceil[9/3] = 3
No of operations required 3-1 = 2 operations

So the formula is ceil((double) A/X) - 1
*/
class Solution {
public:
    bool isPoss(int mid, vector<int>& nums, int maxOperations) {
        int reqOperations = 0;
        for(int &num : nums){
            reqOperations += ceil((double)num/mid) - 1;
        }

        return reqOperations <= maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int s = 1;
        int e = 1e9;

        int ans;
        while(s <= e) {
            int mid = s + (e-s)/2;

            if(isPoss(mid, nums, maxOperations)){
                e = mid - 1;
            }
            else
                s = mid + 1;
        }

        return s;
    }
};