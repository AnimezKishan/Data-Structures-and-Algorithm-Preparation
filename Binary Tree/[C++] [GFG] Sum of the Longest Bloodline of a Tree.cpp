/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    void solve(Node* root, int lvl, int &maxLvl, int sum, int &maxSum)
    {
        if(root == NULL)
        {
            if(lvl > maxLvl)
            {
                maxLvl = lvl;
                maxSum = sum;
            }
            else if(lvl == maxLvl)
            {
                maxSum = max(sum, maxSum);
            }
            return;
        }
        
        sum += root->data;
        solve(root->left, lvl+1, maxLvl, sum, maxSum);
        solve(root->right, lvl+1, maxLvl, sum, maxSum);
        
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int lvl = 0;
        int maxLvl = 0;
        
        int sum = 0;
        int maxSum = INT_MIN;
        
        solve(root, lvl, maxLvl, sum, maxSum);
        return maxSum;
    }
};