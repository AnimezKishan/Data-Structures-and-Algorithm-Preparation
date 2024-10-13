/*
-> Create a min heap of k size.
-> Insert first elements of all k lists inside min heap.
-> Keep track of min & max.
-> Until min heap is not empty
    -> Update min
    -> Update range
    -> Update max 
*/

/*
T.C -> O(n*k log(k))
S.C -> O(k)
*/
// custom DS to store the value and from which row and column it belongs to.
class Node{
    public:
    int data, i, j;

    Node(int data, int i, int j) {
        this->data = data;
        this->i = i;
        this->j = j;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // comparator for replicate min heap behaviour for our custom DS
        auto lambda = [&](Node *a, Node *b) {
            return a->data > b->data;
        };

        int mini = INT_MAX, maxi = INT_MIN, k = nums.size();
        priority_queue<Node*, vector<Node*>, decltype(lambda)> pq(lambda);

        // insert first elements of K lists into min heap
        for(int i=0; i<k; i++){
            int elem = nums[i][0];
            mini = min(mini, elem);
            maxi = max(maxi, elem);

            pq.push(new Node(elem, i, 0));
        }

        int ansMin = mini, ansMax = maxi;
        while(!pq.empty()) {
            // update mini
            Node *temp = pq.top();
            mini = temp->data;
            pq.pop();

            // check for range, if any smaller range found then update the ans
            if((maxi - mini) < (ansMax - ansMin)) {
                ansMax = maxi;
                ansMin = mini;
            }

            // for the current min value, check for next element in it's list
            if(temp->j+1 < nums[temp->i].size()){
                // check for max 
                maxi = max(maxi, nums[temp->i][temp->j+1]);
                // push next element into min heap
                pq.push(new Node(nums[temp->i][temp->j+1], temp->i, temp->j+1));
            }
            else // if any of the list goes out of bound as we need all k list to check for range
                break;
        }

        return {ansMin, ansMax};
    }
};