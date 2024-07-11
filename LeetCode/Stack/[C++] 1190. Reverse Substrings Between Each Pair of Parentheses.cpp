class Solution {
public:
    string reverseParentheses(string s) {
        int idx = 0;
        stack<int> st;
        string ans = "";

        for(char &ch : s){

            // store the position of element after ( 
            if(ch == '('){
                st.push(idx);
            }
            // if ) found, reverse the string by taking starting position of just previously found ( 
            else if(ch == ')'){
                reverse(ans.begin()+st.top(), ans.end());
                st.pop();
            }
            else{
                ans += ch;
                idx++;
            }
        }

        return ans;
    }
};