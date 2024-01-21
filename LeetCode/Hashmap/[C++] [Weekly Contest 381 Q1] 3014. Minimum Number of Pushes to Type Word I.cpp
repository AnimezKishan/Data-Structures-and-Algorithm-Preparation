class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<int, vector<int>> iToA;
        unordered_map<int, int> nToP;
        
        int elem = 0;
        int ans = 0;
        for(int i=0;i<word.length();i++){
            
            if(nToP.find(word[i]-'a') == nToP.end()){
                iToA[elem%8].push_back(word[i]-'a');
                nToP[word[i]-'a'] = iToA[elem%8].size();
                elem++;
            }
            
            ans += nToP[word[i]-'a']; 
        }
        
        return ans;
    }
};