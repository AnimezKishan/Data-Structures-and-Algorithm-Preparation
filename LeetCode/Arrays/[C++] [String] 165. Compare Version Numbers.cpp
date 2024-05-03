// stringstream STL - seperate string according to delimiter (.)
// Example "1.5.06" = { "1", "5", "06" }

class Solution {
public:
    vector<string> getTokens(string version){
        vector<string> tokens;
        stringstream ss(version);
        string token = "";

        while(getline(ss, token, '.'))
            tokens.push_back(token);
        
        return tokens;

    }
    int compareVersion(string version1, string version2) {
        vector<string> v1, v2;
        v1 = getTokens(version1);
        v2 = getTokens(version2);
        
        int m = v1.size(), n = v2.size();
        int i = 0;

        while(i<m || i<n){
            int temp1 = i<m ? stoi(v1[i]) : 0;
            int temp2 = i<n ? stoi(v2[i]) : 0;

            if(temp1 < temp2)
                return -1;
            else if(temp1 > temp2)
                return 1;
            
            i++;
        }

        return 0;
    }
};