/*

'i' is assigned to iterate through 1 --> n.
'j' is assigned to iterate through elements of target.

Since the elements of target is strictly increasing, if the iterated element of target (i) is equal to the iterated no. (j)
-> Push it.
-> Then, iterate to the next element of target.

Else,
->Push it and then Pop it.


Time complexity: O(n)
Space complexity: O(1)

*/

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int j=0;
        for(int i=1;i<=n && j<target.size();i++)
        {
            if(target[j] == i)
            {
                ans.push_back("Push");
                j++;
            }
            else
            {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};