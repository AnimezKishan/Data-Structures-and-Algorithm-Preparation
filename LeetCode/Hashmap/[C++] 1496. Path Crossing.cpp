class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> visited;

        int x = 0, y = 0;
        string key = to_string(x)+"_"+to_string(y);
        visited.insert(key);
        for(int i=0;i<path.length();i++){
            if(path[i] == 'E')
                x++;
            else if(path[i] == 'W')
                x--;
            else if(path[i] == 'N')
                y++;
            else
                y--;
            
            key = to_string(x)+"_"+to_string(y);

            if(visited.find(key) != visited.end())
                return true;
            
            visited.insert(key);
        }

        return false;
    }
};