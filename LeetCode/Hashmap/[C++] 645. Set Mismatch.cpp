class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> map(n+1);
        int totalSum = (n*(n+1))/2;
        int temp = 0;
        int tempSum = 0;

        for(int i=0;i<n;i++){
            map[nums[i]]++;
            if(map[nums[i]] > 1)
            {
                temp = nums[i];
                continue;
            }
            else{
                tempSum += nums[i];
            }
        }

        return {temp, totalSum-tempSum};
    }
};