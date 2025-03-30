class Solution {
    public:
        vector<int> partitionLabels(string s) {
            int n = s.length();
    
            unordered_map<char, int> lastPos;
            for(int i=0; i<n; i++) {
                lastPos[s[i]] = i;
            }
    
            vector<int> ans;
            for(int i=0; i<n; i++) {
                int tempPos = lastPos[s[i]];
    
                for(int j=i; j<=tempPos; j++) {
                    if(lastPos[s[j]] > tempPos) {
                        tempPos = lastPos[s[j]];
                    }
                }
    
                ans.push_back(tempPos - i + 1);
                i = tempPos;
            }
    
            return ans;
        }
    }; 