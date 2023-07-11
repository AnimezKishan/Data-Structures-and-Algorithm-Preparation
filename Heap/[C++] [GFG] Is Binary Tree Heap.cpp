// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

/*
-> Firstly, check if it's a complete binary tree or not.
-> Then, check if it is in max heap order or not.
*/

/*
T.C -> O(n)
S.C -> O(n)
*/
class Solution {
  public:
    int countNode(struct Node* root)
    {
        if(root == NULL)
            return 0;
        
        int ans = 1 + countNode(root->left) + countNode(root->right);
        return ans;
    }
    
    bool isCBT(struct Node* root, int i, int cnt)
    {
        if(root == NULL)
            return true;
        
        //when a index position of node exceeds the total number of nodes that means it is not a CBT.
        if(i >= cnt)
            return false;
        
        else
        {
            bool left = isCBT(root->left, 2*i+1, cnt);
            bool right = isCBT(root->right, 2*i+2, cnt);
            return left && right;
        }
    }
    
    bool isMaxOrder(struct Node* root)
    {
        if(root->left == NULL && root->right == NULL)
            return true;
        
        if(root->right == NULL)
            return (root->data > root->left->data);
        else
        {
            bool left = isMaxOrder(root->left);
            bool right = isMaxOrder(root->right);
            
            if(left && right && (root->data > root->left->data && root->data >root->right->data))
                return true;
            else
                return false;    
        }
        
    }
    bool isHeap(struct Node* tree) {
        int index = 0;
        if(isCBT(tree, index, countNode(tree)) && isMaxOrder(tree))
            return true;
        else
            return false;
    }
};