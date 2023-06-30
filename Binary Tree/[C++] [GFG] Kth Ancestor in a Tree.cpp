/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function

/*
 TC -> O(n)
 SC -> O(max height)
*/

Node* solve(Node *root, int &k, int node)
{
    if(root == NULL)
        return NULL;
    
    if(root->data == node)
        return root;
    
    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);
    
    if(leftAns != NULL && rightAns == NULL)
    {
        k--;
        if(k<=0)
        {
            //so that it cannot reach k=0 again.
            k = INT_MAX;
            //lock the ans
            return root;
        }
        return leftAns;
    }
    
    if(leftAns == NULL && rightAns != NULL)
    {
        k--;
        if(k<=0)
        {
            //so that it cannot reach k=0 again.
            k = INT_MAX;
            //lock the ans
            return root;
        }
        return rightAns;
    }
    return NULL;
    
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    Node* ans = solve(root, k, node);
    if(ans == NULL || ans->data == node)
        return -1;
    else
        return ans->data;
}
