class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();

        vector<int> lastIndex(26);
        vector<bool> visited(26, false);

        //Set the last appearance of character 
        for(int i=0;i<n;i++)
        {
            char ch = s[i];
            lastIndex[ch-'a'] = i;
        }

        string result;
        for(int i=0;i<n;i++)
        {
            char ch = s[i];

            if(visited[ch-'a'] == true)
                continue;

            /*
            1. result string should not be empty.
            2. If last character of result is greater than current character.
            3. Also, If result's last character also appears later, so we can pop it now and will insert the later one.
            */
            while(result.length() > 0 && result.back() > ch && lastIndex[result.back()-'a'] > i)
            {
                visited[result.back()-'a'] = false;
                result.pop_back();
            }

            result.push_back(ch);
            visited[ch-'a'] = true;
        }

        return result;
    }
};