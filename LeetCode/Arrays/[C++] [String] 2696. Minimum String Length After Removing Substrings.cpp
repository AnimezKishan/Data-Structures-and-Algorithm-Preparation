class Solution {
public:
    int minLength(string s) {
        string temp;
        for(char ch:s){
            if((ch == 'B' && temp.size() && temp.back() == 'A') || (ch == 'D' && temp.size() && temp.back() == 'C'))
                temp.pop_back();
            else
                temp.push_back(ch);
        }

        return temp.size();
    }
};