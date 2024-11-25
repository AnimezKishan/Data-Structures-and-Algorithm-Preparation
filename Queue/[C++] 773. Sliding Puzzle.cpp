// BFS

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";

        for(int i=0; i<2; i++) {
            for(int j=0; j<3; j++)
                start += to_string(board[i][j]);
        }

        string target = "123450";
        unordered_map<int, vector<int>> mp;

        // if the zero is in ith index, index of values it could be swapped with.
        mp[0] = {1, 3};
        mp[1] = {0, 2, 4};
        mp[2] = {1, 5};
        mp[3] = {0, 4};
        mp[4] = {1, 3, 5};
        mp[5] = {2, 4};

        queue<string> q;
        q.push(start);
        unordered_set<string> visited;
        visited.insert(start);

        int lvl = 0;
        while(!q.empty()) { 
            int n = q.size();

            while(n--) {
                string curr = q.front();
                q.pop();

                if(curr == target)
                    return lvl;

                int idxOfZero = curr.find('0');
                for(int &swapIdx : mp[idxOfZero]) {
                    string swappedStr = curr;
                    swap(swappedStr[idxOfZero], swappedStr[swapIdx]);
                    if(visited.find(swappedStr) == visited.end()) {
                        visited.insert(swappedStr);
                        q.push(swappedStr);
                    }
                }
            }

            lvl++;
         }

         return -1;
    }
};