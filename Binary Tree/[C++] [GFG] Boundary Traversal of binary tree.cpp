/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*
Algo :- 
-> Firstly hardle the left most childs except the leaf node.
-> Then, takle all leaf nodes.
-> Lastly, handle all right most child nodes excpet leaf node.
*/

/*
T.C -> O(n)
S.C ->O(max height of tree) 
*/
class Solution {
public:
    void traverseLeft(Node* root, vector<int> &ans){
        if((root == NULL) || (root->left == NULL && root->right == NULL))
            return;
        
        ans.push_back(root->data);
        if(root->left)
            traverseLeft(root->left, ans);
        else
            traverseLeft(root->right, ans);
    }
    
    void traverseLeaf(Node* root, vector<int> &ans){
        if(root == NULL)
            return;
            
        if(root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
            return;
        }
        
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }
    
    void traverseRight(Node* root, vector<int> &ans){
        if((root == NULL) || (root->left == NULL && root->right == NULL))
            return;
        
        if(root->right)
            traverseRight(root->right, ans);
        else
            traverseRight(root->left, ans);
            
        ans.push_back(root->data);
    }
    
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root == NULL)
            return ans;
        
        ans.push_back(root->data);
        
        //traverse left part
        traverseLeft(root->left, ans);
        
        //traverse leaf nodes
        //traverse left subtree
        traverseLeaf(root->left, ans);
        
        //traverse right subtree
        traverseLeaf(root->right, ans);
        
        //traverse right part
        traverseRight(root->right, ans);
        
        return ans;
    }
};