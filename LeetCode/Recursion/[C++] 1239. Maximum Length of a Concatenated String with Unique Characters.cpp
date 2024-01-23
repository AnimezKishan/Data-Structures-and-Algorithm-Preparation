class Solution {
public:
    int n;
    bool hasDuplicate(string &s1, string &s2){
        vector<int> m(26, 0);

        for(char &ch:s1){
            if(m[ch-'a'] > 0)
                return true;
            
            m[ch-'a']++;
        }

        for(char &ch:s2){
            if(m[ch-'a'] > 0)
                return true;
        }

        return false;
    }
    int solve(int i, string temp, vector<string> &arr){
        if(i >= n)
            return temp.length();
        
        int include = 0, exclude = 0;
        if(hasDuplicate(arr[i], temp)){
            exclude = solve(i+1, temp, arr);
        }
        else{
            exclude = solve(i+1, temp, arr);
            include = solve(i+1, temp+arr[i], arr);
        }

        return max(include, exclude);
    }
    int maxLength(vector<string>& arr) {
        n = arr.size();

        return solve(0, "", arr);
    }
};