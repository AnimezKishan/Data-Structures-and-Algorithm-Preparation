class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, unordered_set<int>> colorMapping;
        unordered_map<int, int> ballToColor;

        vector<int> ans;
        for(vector<int> &query : queries) {
            int currBall = query[0];
            int toColor = query[1];

            if(ballToColor.find(currBall) == ballToColor.end()) {
                ballToColor[currBall] = toColor;
                colorMapping[toColor].insert(currBall);
            }
            else {
                int currColor = ballToColor[currBall];
                colorMapping[currColor].erase(currBall);
                if(colorMapping[currColor].size() == 0)
                    colorMapping.erase(currColor);
                
                ballToColor[currBall] = toColor;
                colorMapping[toColor].insert(currBall);
            }

            ans.push_back(colorMapping.size());
        }

        return ans;
    }
};