class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1, s2;

        for(int i=0;i<s.length();i++){
            if(s[i] == '#' && s1.empty())
                continue;
            else if(s[i] != '#')
                s1.push(s[i]);
            else
                s1.pop();
        }

        for(int i=0;i<t.length();i++){
            if(t[i] == '#' && s2.empty())
                continue;
            else if(t[i] != '#')
                s2.push(t[i]);
            else
                s2.pop();
        }

        while(!s1.empty() && !s2.empty()){
            auto t1 = s1.top();
            auto t2 = s2.top();
            s1.pop();
            s2.pop();
            if(t1 != t2)
                return false;
        }

        if(s1.empty() && s2.empty()) 
            return true;
        else
            return false;
    }
};