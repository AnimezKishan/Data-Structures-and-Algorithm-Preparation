/*
Two - Pass Solution
Find x > y or y > x and accordingly remove substrings of greater points and then of lower points.
Why this always work?

Suppose, here x > y
s = "baba"
if x is considered first, it results in x+y
if y is considered first, it results in y+y

Since, x > y
x+y > y+y (Add y both side)
Hence Proved.
*/

class Solution {
public:
    string removeSubStr(string &s, string &matchStr){
        stack<int> st;

        // Remove all matchStr substrings from string.
        for(char &ch : s){
            if(ch == matchStr[1] && !st.empty() && st.top() == matchStr[0]){
                st.pop();
            }
            else
                st.push(ch);
        }

        string str = "";
        while(!st.empty()){
            str += st.top();
            st.pop();
        }

        reverse(str.begin(), str.end());
        return str;
    }
    int maximumGain(string s, int x, int y) {
        int n = s.length();
        int ans = 0;
        string maxStr = (x > y) ? "ab" : "ba";
        string minStr = (x < y) ? "ab" : "ba";

        // First Pass
        string temp_first = removeSubStr(s, maxStr);
        int firstL = temp_first.length();
        int removedPairCount = (n - firstL)/2;
        ans += removedPairCount * max(x, y);

        // Second Pass
        string temp_second = removeSubStr(temp_first, minStr);
        int secondL = temp_second.length();
        removedPairCount = (firstL - secondL)/2;
        ans += removedPairCount * min(x, y);

        return ans;
    }
};