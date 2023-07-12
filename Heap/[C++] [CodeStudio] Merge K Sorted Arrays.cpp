/*
-> Insert first element of each array inside a min heap.
-> Put top element of min heap inside a separate array and insert next element of same array inside min heap.

-> Create a separate Data Structure to keep track of which array to access.
*/

/*
T.C -> O(n*k*log(k)) [n is the size of a particular array] 
S.C -> O(k) + O(n*k) -> O(n*k)
*/

#include <bits/stdc++.h> 

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

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<Node*, vector<Node*>, compare> min_heap;

    //Step 1
    for(int i=0;i<k;i++)
    {
        Node* temp = new Node(kArrays[i][0], i, 0);
        min_heap.push(temp);
    }

    //Step 2
    vector<int> ans;
    
    while(min_heap.size() > 0)
    {
        Node* temp = min_heap.top();
        ans.push_back(temp->data);
        min_heap.pop();

        int i = temp->i;
        int j = temp->j;

        if(j+1 < kArrays[i].size())
        {
            Node* next = new Node(kArrays[i][j+1], i, j+1);
            min_heap.push(next);
        }
    }
    return ans;
}
  