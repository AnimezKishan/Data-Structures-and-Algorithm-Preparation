//Two Pointer

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int i = 0, j = numbers.size()-1;
        while(i<=j)
        {
            int sum = numbers[i] + numbers[j];
            if(sum == target)
            {
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans;
            }

            if(sum < target)
                i++;
            else
                j--;
        }
        return ans;
    }
};