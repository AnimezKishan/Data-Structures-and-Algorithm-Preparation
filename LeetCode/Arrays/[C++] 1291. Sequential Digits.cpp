// Iterative DFS Approach
/*
Time Complexity: O(1)
Space Complexity: O(1)

Explanation for Time Complexity:
In the for loop,
First we take i = 1, we get num as 1, 12, 123, ..., 123456789 in worst case. (9 steps)
i = 2, we get num as 2, 23, 234, ...., 23456789 in worst case (8 steps)
like wise for i=9, we get num as only 9.
Therefore in worst case, we will get (9+8+7+...+1) = 9*10/2 = 45 steps which is constant!

Sorting in the worst case can take 45log45 which is constant. Hence, O(1).

So, we can say that time complexity is : O(1)
*/

class Solution {
public:
    vector<int> ans;
    void dfs(int i, int num, int low, int high){
        if(num >= low && num <= high)
            ans.push_back(num);
        
        if(i>9 || num>high)
            return;
        
        dfs(i+1, num*10+i, low, high);
    }
    vector<int> sequentialDigits(int low, int high) {
        for(int i=1;i<=9;i++)
            dfs(i, 0, low, high);
        
        sort(begin(ans), end(ans));
        return ans;
    }
};


// Approach II
/*
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> possibleVals = {12, 23, 34, 45, 56, 67, 78, 89, 123, 234, 345, 456, 567, 678, 789, 1234, 2345, 3456, 4567, 5678, 6789, 12345, 23456, 34567, 45678, 56789, 123456, 234567, 345678, 456789, 1234567, 2345678, 3456789, 12345678, 23456789, 123456789};
        vector<int> ans;
        for(int i=0;i<possibleVals.size();i++){
            if(possibleVals[i] >= low && possibleVals[i]<=high){
                ans.push_back(possibleVals[i]);
            }
            else if(possibleVals[i] > high)
                break;
        }

        return ans;
    }
};
*/