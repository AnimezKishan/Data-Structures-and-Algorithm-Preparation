/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

/*
T.C -> O(n*log(n)) [log(n) for accessing map] {can be done in O(n) using unordered_map}
S.C -> O(n)
*/

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root == NULL)
            return ans;
        
        //represents horizontal distance and node's data
        map<int, int> topNode;
        
        //pair represents the node and its horizontal distance
        queue<pair<Node*, int>> q;
        
        q.push(make_pair(root, 0));
        
        while(!q.empty())
        {
            pair<Node*, int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            if(topNode.find(hd) == topNode.end())
                topNode[hd] = frontNode->data;
            
            if(frontNode->left)
                q.push(make_pair(frontNode->left, hd-1));
            if(frontNode->right)
                q.push(make_pair(frontNode->right, hd+1));
        }
        
        for(auto i:topNode)
        {
            ans.push_back(i.second);
        }
        return ans;
    }

};