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
class Node{
    public:
    int data;
    int i;
    int j;

    Node(int d, int row, int col)
    {
        this->data = d;
        this->i = row;
        this->j = col;
    }
};

class compare{
    public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        priority_queue<Node*, vector<Node*>, compare> min_heap;
        int k = nums.size();

        //Insert first elements of all k lists inside min heap.
        for(int i=0;i<k;i++)
        {
            int element = nums[i][0];
            mini = min(mini, element);
            maxi = max(maxi, element);
            min_heap.push(new Node(element, i, 0)); 
        }
        
        int start = mini, end = maxi;
        while(!min_heap.empty())
        {
            //Update mini
            Node *temp = min_heap.top();
            mini = temp->data;
            min_heap.pop();

            //Update Range.
            if((maxi-mini) < (end-start))
            {
                start = mini;
                end = maxi;
            }

            //Update maxi and push next element in min heap.
            if(temp->j+1 < nums[temp->i].size())
            {
                maxi = max(maxi, nums[temp->i][temp->j+1]);
                min_heap.push(new Node(nums[temp->i][temp->j+1], temp->i, temp->j+1));
            }
            else
                break;
        }
        return {start, end};
    }
};