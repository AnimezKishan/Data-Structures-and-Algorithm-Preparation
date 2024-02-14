// Two Pointer 

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int pIndex = 0, nIndex = 1;

        for(int &i:nums){
            if(i<0){
                ans[nIndex] = i;
                nIndex += 2;
            }
            else{
                ans[pIndex] = i;
                pIndex += 2;
            }
        }

        return ans;
    }
};


// Queue
/*
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> plus, minus;
        for(int &i:nums){
            if(i<0)
                minus.push(i);
            else
                plus.push(i);
        }

        int alternate = true;
        int i = 0;
        
        while(!plus.empty() || !minus.empty()){
            if(alternate){
                nums[i++] = plus.front();
                plus.pop();
            }
            else{
                nums[i++] = minus.front();
                minus.pop();
            }

            alternate = !alternate;
        }

        return nums;
    }
};
*/