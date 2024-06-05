class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> count(26, 0);

        for(char &ch : words[0])
            count[ch-'a']++;

        for(int i=1; i<words.size(); i++){
            vector<int> temp(26, 0);
            for(char &ch : words[i])
                temp[ch-'a']++;

            for(int i=0;i<26;i++)
                count[i] = min(count[i], temp[i]);
        }

        vector<string> ans; 
        for(int i=0;i<26;i++){
            int n = count[i];
            while(n){
                ans.push_back(string(1, i+'a'));
                n--;
            }
        }

        return ans;
    }
};