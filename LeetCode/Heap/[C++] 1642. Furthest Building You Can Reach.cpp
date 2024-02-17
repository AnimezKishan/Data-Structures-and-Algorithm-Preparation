/*
-> move forards by comsuming all ladders.
-> when no ladders left, Try to fill the current minimum gap with bricks
    -> If possible filling, pop out that minimum gap since it got filled with bricks instead of ladder.
    -> If not possible, it means the bricks are not sufficient to even fill the current minimum gap, so return it as furthest building index.

** At most the size of min_heap = ladders, and when size tries to exceeds, the minGap is tried to filled using bricks.
*/

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for(int i=0;i+1<heights.size();i++){
            int gap = heights[i+1] - heights[i];

            if(gap > 0){
                min_heap.push(gap);

                if(min_heap.size() > ladders){
                    bricks -= min_heap.top();
                    min_heap.pop();
                }

                if(bricks < 0)
                    return i;
            }
        }

        return heights.size() - 1;
    }
};