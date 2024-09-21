// DFS

class Solution {
public:
    vector<int> ans;
    bool dfs(int i, int &n){
        if(i > n)
            return true;
        
        ans.push_back(i);

        for(int newI=0; newI<=9; newI++) {
            bool limit = dfs(i*10 + newI, n);
            if(limit)
                break;
        }

        return false;
    }
    vector<int> lexicalOrder(int n) {
        for(int i=1; i<10; i++) {
            if(i <= n)
                dfs(i, n);
        }

        return ans;
    }
};