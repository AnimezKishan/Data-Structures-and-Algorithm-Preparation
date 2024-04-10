/*
Pattern in bottom to top manner

[2,13,3,11,5,17,7]
[3,11,5,17,7,13]
[5,17,7,13,11]
[7,13,11,17]
[11,17,13]
[13,17]
[17]

*/

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(begin(deck), end(deck), greater<int>());
        deque<int> q={deck[0]};


        for(int i=1;i<deck.size();i++){
            int temp = q.back();
            q.pop_back();

            q.push_front(temp);
            q.push_front(deck[i]);
        }

        return vector<int>(q.begin(), q.end());
    }
};