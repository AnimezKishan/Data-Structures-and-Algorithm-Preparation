class Solution {
public:
    int doOperation(int a, int b, string op){
        if(op == "+")
            return b+a;
        if(op == "-")
            return b-a;
        if(op == "*")
            return b*a;
        else
            return floor(b/a);
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for(int i=0;i<tokens.size();i++){
            if(!s.empty())
                cout<<s.top()<<endl;
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();

                int final = doOperation(a, b, tokens[i]);
                s.push(final);
            }
            else
                s.push(stoi(tokens[i]));
        }

        return s.top();
    }
};