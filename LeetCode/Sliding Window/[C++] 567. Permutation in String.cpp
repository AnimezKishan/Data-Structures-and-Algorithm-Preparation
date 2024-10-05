class Solution {
public:
    bool isEqual(vector<int> &c1, vector<int> &c2) {
        for(int i = 0; i<26; i++)
            if(c1[i] != c2[i])
                return false;
        
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        vector<int> count1(26, 0);
        for(char ch : s1)
            count1[ch-'a']++;

        int n1 = s1.size(), n2 = s2.size();
        int i = 0, j = 0;
        vector<int> count2(26, 0);
        while(j < n2) {
            count2[s2[j]-'a']++;

            while(j-i+1 > n1) {
                count2[s2[i]-'a']--;
                i++;
            }

            if(j-i+1 == n1 && isEqual(count1, count2))
                return true;
            j++;
        }

        return false;
    }
};