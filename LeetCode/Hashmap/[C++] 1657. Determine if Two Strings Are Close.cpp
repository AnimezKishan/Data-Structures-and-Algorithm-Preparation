// Hashmap + Sorting

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        if(m != n)
            return false;
        
        vector<int> count1(26, 0), count2(26, 0);
        for(int i=0;i<m;i++){
            count1[word1[i]-'a']++;
            count2[word2[i]-'a']++;
        }

        for(int i=0;i<26;i++)
        {
            if((count1[i] && !count2[i]) || (!count1[i] && count2[i]))
                return false;
        }

        sort(begin(count1), end(count1));
        sort(begin(count2), end(count2));
        return count1 == count2;
    }
};