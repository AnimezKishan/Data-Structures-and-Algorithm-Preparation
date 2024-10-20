class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        stack<char> op;

        for(int i=0; i<expression.length(); i++) {
            if(expression[i] == ',')
                continue;
            else if(expression[i] == '&' || expression[i] == '|' || expression[i] == '!')
                op.push(expression[i]);
            else if(expression[i] == ')'){
                bool final = st.top() == 'f' ? false : true;
                while(!st.empty() && st.top() != '('){
                    bool curr = st.top() == 'f' ? false : true;
                    st.pop();

                    if(op.top() == '&')
                        final = final & curr;
                    else if(op.top() == '|')
                        final = final | curr;
                    else if(op.top() == '!')
                        final = !final;
                }

                // remove '('
                st.pop();
                // remove used operation
                op.pop();
                st.push(final == false ? 'f' : 't');
            }
            else
                st.push(expression[i]);
            
        }

        return st.top() == 'f' ? false : true;
    }
};