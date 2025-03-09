// Sliding Window

class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            int n = colors.size(), N = n + k - 1;
            for(int i=0; i<k-1; i++) {
                colors.push_back(colors[i]);
            }
    
            int i=0, j=1, ans = 0;
            while(j < N) {
                if(colors[j] == colors[j-1]) {
                    i = j;
                    j++;
                    continue;
                }
    
                if(j-i+1 == k) {
                    i++;
                    ans++;
                }
    
                j++;
            }
    
            return ans;
        }
    };