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

// O(n)
/*
class Solution {
public:
    bool isVowel(char &v){
        if(v == 'A' || v == 'E' || v == 'I' || v == 'O' || v == 'U' || v == 'a' || v == 'e' || v == 'i' || v == 'o' || v == 'u')
        return true;
    return false;
    }
    string sortVowels(string s) {
        int n = s.length();
        vector<int> vowelCount(130, 0);

        for(int i=0; i<n; i++){
            if(isVowel(s[i]))
                vowelCount[int(s[i])]++;
        }

        int j = 0;
        for(int i=0; i<n; i++){
            while(j < 130 && !vowelCount[j]){
                j++;
            }

            if(isVowel(s[i])){
                s[i] = char(j);
                vowelCount[j]--;
            }
        }

        return s;
            
    }
};
*/