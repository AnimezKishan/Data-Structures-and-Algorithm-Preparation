class Solution {
private:
    void subset(vector<int> &n, vector<vector<int>> &ans, vector<int> output, int i){
        if(i >= n.size())
        {
            ans.push_back(output);
            return;
        }
        //exclude the value
        subset(n, ans, output, i+1);

        //include the value
        int element = n[i];
        output.push_back(element);
        subset(n, ans, output, i+1);

    }
public:
    vector<vector<int>> subsets(vector<int>& n) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        subset(n, ans, output, index);
        return ans;
    }
};