class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target)
            return 0;
        
        unordered_map<int, vector<int>> bus;
        for(int i=0;i<routes.size();i++)
        {
            for(auto route:routes[i])
                bus[route].push_back(i);  //each stop's buses
        }

        vector<bool> bus_taken(routes.size());
        queue<int> q;

        //taking all buses from source
        for(auto start:bus[source]){
            bus_taken[start] = 1;
            q.push(start);
        }

        int ans = 0;
        while(!q.empty())
        {
            ++ans;
            //taking all buses possible from a stop
            for(int i=q.size();i>0;--i)
            {
                int currentBus = q.front();
                q.pop();

                //all routes for current bus
                for(auto route:routes[currentBus])
                {
                    if(route == target)
                        return ans;
                    
                    //all buses from current stop
                    for(int k=0;k<bus[route].size();k++)
                    {
                        //if the bus is taken or not
                        if(!bus_taken[bus[route][k]])
                        {
                            bus_taken[bus[route][k]] = 1;
                            q.push(bus[route][k]);
                        }
                    }
                }
            }
        }
        return -1;
    }
};