// Two - Pointer

class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        // so that larger string stays in s1
        if(s1.length() < s2.length())
            swap(s1, s2);

        vector<string> vec1, vec2;
        // splits the string on the basis of space
        stringstream ss1(s1);
        string token;
        while(ss1 >> token)
            vec1.push_back(token);

        stringstream ss2(s2);
        while(ss2 >> token)
            vec2.push_back(token);

        int i = 0, j = vec1.size()-1;
        int x = 0, y = vec2.size()-1;
        
        while(x < (y+1) && i < (j+1) && vec1[i] == vec2[x]){
            x++;
            i++;
        }

        while(y >= x && vec1[j] == vec2[y]){
            y--;
            j--;
        }
        
        return x > y;
    }
};