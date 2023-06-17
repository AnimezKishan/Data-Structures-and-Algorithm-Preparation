#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;
    
    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){
    
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    
    if(data == -1)
        return NULL;
        
    cout<<"Enter element to be inserted at left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter element to be inserted at right of "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        if(temp == NULL)
        {
            //if a level is fully traversed, travel child nodes in a new line.
            cout<<endl;
            if(!q.empty())
            {
                //if any child element present
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        
    }
}

int main()
{
    node* root = NULL;
    root = buildTree(root);
    
    cout<<"Level Order Traversal Output:"<<endl;
    levelOrderTraversal(root);
    return 0;
}
