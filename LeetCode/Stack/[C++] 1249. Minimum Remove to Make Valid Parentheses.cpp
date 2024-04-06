class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> st;

        for(int i=0;i<s.length();i++){
            if(s[i] == '(')
                st.push({'(', i});
            
            else if(s[i] == ')' && !st.empty() && st.top().first == '(')
                st.pop();

            else if(s[i] == ')')
                st.push({')', i});
        }

        // while(!st.empty()){
        //     cout<<st.top().first<< " -> "<<st.top().second;
        //     st.pop();
        // }

        string ans;

        for(int i=s.length()-1;i>=0;i--){
            if((s[i] == '(' || s[i] == ')') && !st.empty() && i == st.top().second){
                st.pop();
            }
            else
                ans.insert(ans.begin(), s[i]);
        }

        return ans;
    }
};