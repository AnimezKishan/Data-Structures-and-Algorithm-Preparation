// Backtracking + Set

class Solution {
    public:
        void solve(string currStr, string &tiles, unordered_set<string> &sequences, vector<bool> &visited) {
            sequences.insert(currStr);
    
            for(int i=0; i<tiles.length(); i++) {
                if(!visited[i]) {
                    visited[i] = true;
                    solve(currStr + tiles[i], tiles, sequences, visited);
                    visited[i] = false;
                }
            }
        }
        int numTilePossibilities(string tiles) {
            unordered_set<string> sequences;
            vector<bool> visited(tiles.length(), false);
    
            solve("", tiles, sequences, visited);
    
            return sequences.size() - 1; // exclude "" (empty string)
        }
    };