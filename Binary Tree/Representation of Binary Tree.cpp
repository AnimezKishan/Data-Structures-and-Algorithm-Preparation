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

void inorder(node* root)
{
    //base case 
    if(root == NULL)
        return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root){
    //base case
    if(root == NULL)
        return;
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    //base case 
    if(root == NULL)
        return;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void buildFromLevelOrder(node* &root)
{
    queue<node*> q;
    cout<<"Enter the data for root: "<<endl;
    int d;
    cin>>d;
    root = new node(d);
    q.push(root);
    
    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        
        cout<<"Enter left node of "<<temp->data<<": ";
        int leftData;
        cin>>leftData;
        if(leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }
        
        cout<<"Enter right node of "<<temp->data<<": ";
        int rightData;
        cin>>rightData;
        if(rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
            
    }
}

int main()
{
    node* root = NULL;
    root = buildTree(root);
    
    cout<<"Level Order Traversal Output:"<<endl;
    levelOrderTraversal(root);

    cout<<endl<<"Inorder Traversal: ";
    inorder(root);
    
    cout<<endl<<"Preorder Traversal: ";
    preorder(root);
    
    cout<<endl<<"Postorder Traversal: ";
    postorder(root);
    
    cout<<endl<<endl;
    buildFromLevelOrder(root);
    cout<<"Level Order Traversal Output:"<<endl;
    levelOrderTraversal(root);
    return 0;
}
