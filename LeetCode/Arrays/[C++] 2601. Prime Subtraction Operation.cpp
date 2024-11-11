class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        vector<int> primeNums;

        for(int i=2; i<1000; i++) {
            int count = 0;
            for(int j=2; j<=i/2; j++) 
                if(i % j == 0)
                    count++;
            
            if(count <= 0)
                primeNums.push_back(i);
        }

        for(int i=n-2; i>=0; i--) {
            if(nums[i] < nums[i+1])
                continue;
            else {
                for(int j=0; j<primeNums.size() && primeNums[j] < nums[i]; j++) {
                    if(nums[i] - primeNums[j] < nums[i+1]) {
                        nums[i] -= primeNums[j];
                        break;
                    }
                }

                if(nums[i] >= nums[i+1])
                    return false;
            }
        }

        return true;
    }
};