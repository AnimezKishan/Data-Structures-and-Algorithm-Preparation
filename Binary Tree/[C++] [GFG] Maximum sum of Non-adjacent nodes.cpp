//Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

/*
pair<a, b> where, 
a -> maxSum by including the current node.
b -> maxSum by excluding the current node.
*/

class Solution{
  public:
    pair<int, int> solve(Node* root)
    {
        if (root == NULL)
            return {0,0};
        
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        
        pair<int, int> temp;
        
        //including the current node
        temp.first = root->data + left.second + right.second;
        
        //excluding the current node
        temp.second = max(left.first, left.second) + max(right.first, right.second);
        
        return temp;
    }
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        // Add your code here
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};