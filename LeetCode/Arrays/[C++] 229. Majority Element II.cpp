//Boyer–Moore majority vote algorithm

//Reference - https://www.youtube.com/watch?v=Q6L5SoS-fTo

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int count1 = 0;
        int major1 = NULL;

        int count2 = 0;
        int major2 = NULL;

        for(int i=0;i<n;i++)
        {
            if(major1 == nums[i])
                count1++;
            else if(major2 == nums[i])
                count2++;
            else if(count1 == 0)
            {
                major1 = nums[i];
                count1++;
            }
            else if(count2 == 0)
            {
                major2 = nums[i];
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        } 

        vector<int> result;
        int freq1 = 0;
        int freq2 = 0;

        for(int &num:nums)
            if(num == major1)
                freq1++;
            else if(num == major2)
                freq2++;
        
        if(freq1 > floor(n/3))
            result.push_back(major1);
        
        if(freq2 > floor(n/3))
            result.push_back(major2);
        
        return result;
    }
};