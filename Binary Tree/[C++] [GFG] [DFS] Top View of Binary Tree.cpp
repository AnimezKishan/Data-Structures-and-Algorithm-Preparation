/*struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    void dfs(Node* root, map<int, pair<int, int>> &topNode, int hd, int vd){
        if(root == NULL)
          return;
        
        if(topNode.find(hd) == topNode.end())
          topNode[hd] = {root->data, vd};
        
        // if a node exist for a horizontal depth, store the node with least vertical depth 
        if(vd < topNode[hd].second)
          topNode[hd] = {root->data, vd};
          
        if(root->left)
          dfs(root->left, topNode, hd-1, vd+1);
        
        if(root->right)
          dfs(root->right, topNode, hd+1, vd+1);
    }
    
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        int hd=0, vd=0;
        
        //Horizontal Distance -> {node value, vertical distance}
        map<int, pair<int, int>> topNode;
        dfs(root, topNode, hd, vd);
        
        for(auto i:topNode)
          ans.push_back(i.second.first);
          
        return ans;
    }

};
