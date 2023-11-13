class Solution {
public:
    typedef pair<int, char> P;
    string sortVowels(string s) {
        priority_queue<P, vector<P>, greater<P>> min_heap;
        for(int i=0;i<s.length();i++){
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'O' || s[i] == 'I' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'i' || s[i] == 'u'){
                min_heap.push({int(s[i]), s[i]});
            }
        }

        for(int i=0;i<s.length();i++){
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'O' || s[i] == 'I' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'i' || s[i] == 'u'){
                auto t = min_heap.top();
                min_heap.pop();
                s[i] = t.second;
            }
        }

        return s;
    }
};