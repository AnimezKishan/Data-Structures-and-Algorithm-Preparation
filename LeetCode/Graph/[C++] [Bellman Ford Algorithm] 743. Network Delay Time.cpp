class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> distance(n, 1e9);

        distance[k-1] = 0;

        for(int i=0;i<n;i++)
        {
            for(auto j:times)
            {
                int u = j[0]-1;
                int v = j[1]-1;
                int w = j[2];
                
                if(distance[u] + w < distance[v])
                    distance[v] = distance[u] + w;
            }
        }

        //if distance of any node is INT_MAX then it is not traversed, then it is impossible for that node to recieve signal.
        if(count(distance.begin(), distance.end(), 1e9))
            return -1;
        return *max_element(distance.begin(), distance.end()); 

    }
};