class Solution {
public:

    
    vector<int> countOfPairs(int n, int x, int y) {
        unordered_map<int, vector<int>> adj;
        vector<int> ans(n);

        if(x != y)
        {
            adj[x].push_back(y);
            adj[y].push_back(x);
        }    
        
        for(int i=1;i<n;i++){
            adj[i].push_back(i+1);
            adj[i+1].push_back(i);
        }
        
        for(int i=1;i<=n;i++){
            queue<int> q;
            q.push(i);

            vector<bool> visited(n+1);
            visited[i] = 1;

            int lvl = 0;
            
            while(!q.empty()){
                for(int sz = q.size(); sz > 0; sz--){
                    int temp = q.front();
                    q.pop();

                    for(int &nbr:adj[temp]){
                        if(!visited[nbr]){
                            q.push(nbr);
                            visited[nbr] = 1;
                            ans[lvl]++;
                        }
                    }
                }
                lvl++;
            }
        }
        return ans;
    }
};