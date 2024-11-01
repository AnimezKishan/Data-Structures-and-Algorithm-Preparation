class Solution {
public:
    string makeFancyString(string s) {
        
        string temp = "";
        for(int j=0; j<s.length(); j++) {
            if(temp.size() >= 2){
                char last = temp.back();
                temp.pop_back();
                char secondLast = temp.back();
                temp.pop_back();
                temp.push_back(secondLast);
                temp.push_back(last);

                if(last == s[j] && secondLast == s[j])
                    continue;
            }
            
            temp.push_back(s[j]);
        }

        return temp;
    }
};