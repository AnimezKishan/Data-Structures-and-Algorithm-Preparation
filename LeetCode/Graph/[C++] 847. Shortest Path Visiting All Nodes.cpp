// BFS + Bit Mask (Bit Manipulation) [Imp. Question]

class Solution {
public:
    typedef pair<int, int> P;
    int shortestPathLength(vector<vector<int>>& graph) {
        int n= graph.size();

        if(n == 0 || n ==1)
            return 0;
        
        //{node, mask}
        queue<P> q;
        //{node, pathMask}
        set<P> visited;

        for(int i=0;i<n;i++)
        {
            int maskValue = (1 << i);
            q.push({i, maskValue});
            visited.insert({i, maskValue});
        }

        //All bits are set.
        int allVisited = (1 << n) - 1;
        int path = 0;
        while(!q.empty())
        {
            int N = q.size();
            path++;
            while(N--)
            {
                auto curr = q.front();
                q.pop();
                
                int node = curr.first;
                int currMask = curr.second;

                for(int &nbr:graph[node])
                {
                    int nextMask = currMask | (1 << nbr);
                    if(nextMask == allVisited)
                        return path;
                    
                    if(visited.find({nbr, nextMask}) == visited.end())
                    {
                        visited.insert({nbr, nextMask});
                        q.push({nbr, nextMask});
                    }
                }
            }
        }
        return -1;
    }
};