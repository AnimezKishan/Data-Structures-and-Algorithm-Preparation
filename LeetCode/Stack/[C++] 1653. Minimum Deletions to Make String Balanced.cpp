class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int ans = 0;

        // we just need the no. and not the actual corrected string.
        for(char &ch:s){
            if(!st.empty() && st.top() == 'b' && ch == 'a')
            {
                st.pop();
                ans++;
            }
            else
                st.push(ch);
        }

        return ans;
    }
};


// Approach II
/* 
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();

        // keep account of no. of 'a' appreaing on right side for each index.
        int countA = 0;
        vector<int> rightA(n);
        for(int i=n-1; i>=0; i--){
            rightA[i] = countA;
            if(s[i] == 'a')
                countA++;
        }

        // pick a index where, no. of 'b' left to it + no. of 'a' right to it is minimum.
        int ans = INT_MAX;
        // On the way, keep account of no. of 'b' appreaing on left side for each index.
        int countB = 0;
        for(int i=0; i<n; i++){
            ans = min(ans, countB + rightA[i]);
            if(s[i] == 'b')
                countB++;
        }

        return ans;

    }
};
*/