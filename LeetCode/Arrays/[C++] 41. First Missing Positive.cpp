// Pre-Requisite - 287. Find the Duplicate Number

/*
Indirectly, It says no.s must be in range of [1,n] in array, and if they all are present then the first missing +ve no. would be n+1.
Now this question falls into the category of 'Array with elements in range of [1, n].
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool flag = 0;

        // check if smallest value of range i.e. 1 is present or not.
        // also convert all -ve no.s and 0s.
        for(int i=0;i<n;i++){
            if(nums[i] <= 0)
                nums[i] = 1;
            else if(nums[i] == 1)
                flag = 1;    
        }

        if(flag == 0)
            return 1;
        
        // Now apply the algo. i.e. consider elements as indices.
        for(int i=0;i<n;i++){
            if(nums[i] <= n){
                int num = abs(nums[i]);
                nums[num-1] = -abs(nums[num-1]); 
            }
        }

        // Search if any element is +ve, if it is then index i+1 is not visited.
        for(int i=0;i<n;i++){
            if(nums[i] > 0)
                return i+1;
        }

        return n+1; 
    }
};