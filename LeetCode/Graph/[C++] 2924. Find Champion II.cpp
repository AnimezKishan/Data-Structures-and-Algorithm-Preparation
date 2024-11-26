class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_map<int, int> indegree;

        for(vector<int> &edge : edges) 
            indegree[edge[1]]++;

        int count = 0, ans;
        
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0){
                count++;
                ans = i;
            }
        }

        return count == 1 ? ans : -1;
    }
};