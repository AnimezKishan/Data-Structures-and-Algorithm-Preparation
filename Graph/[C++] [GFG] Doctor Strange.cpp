class Solution{
    public:
void findAP(unordered_map<int,vector<int>> &store,vector<int> &disc,vector<int> &low,vector<bool> &vis,int &timer, int &parent, int node, set<int> &ans){
       vis[node]=true;
       disc[node]=timer;
       low[node]=timer;
       timer++;
       
       int child=0;
       for(auto neigh: store[node]){
           if(neigh == parent){
               continue;
           }
           if(vis[neigh]==false){
               
               findAP(store,disc,low,vis,timer,node,neigh,ans);
               low[node]=min(low[node],low[neigh]);
               if(low[neigh]>=disc[node] && parent != -1){
                   ans.insert(node);
               }
               child++;
               
           }
           else{
               low[node] = min(low[node],disc[neigh]);
           }
       }
       if(child>1 && parent == -1){
           ans.insert(node);
       }
   }
   
   
   int doctorStrange(int N, int M, vector<vector<int>> & graph)
   {
        //Write your code here
        
        
        unordered_map<int,vector<int>> store;
        vector<int> disc(N+1,-1);
        vector<bool> vis(N+1,false);
        vector<int> low(N+1,-1);
        int timer=0;
        int parent = -1;
        for(int i=1;i<=N;i++){
            vector<int> temp;
            store[i]=temp;
        }
        for(int i=0;i<M;i++){
            int u = graph[i][0];
            int v = graph[i][1];
            store[u].push_back(v);
            store[v].push_back(u);
            
        }
        set<int> ans;
        for(int i=1;i<=N;i++){
            if(vis[i] == false){
                findAP(store,disc,low,vis,timer,parent,i,ans);
            }
        }
        if(M==1){
            return 0;
        }
        
        return ans.size();
        
        
   }
};