#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
    
};

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty())
    {
        Node* temp = q.front();
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

void inorder(Node* root)
{
    //base case 
    if(root == NULL)
        return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    //base case
    if(root == NULL)
        return;
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    //base case 
    if(root == NULL)
        return;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

//T.C -> O(log(n))
Node* insertIntoBST(Node* root, int d)
{
    if(root == NULL)
    {
        root = new Node(d);
        return root;
    }
    
    if(d > root->data)
    {
        root->right = insertIntoBST(root->right, d);
    }
    
    else{
        root->left = insertIntoBST(root->left, d);
    }
    
    return root;
}

void takeInput(Node* &root)
{
    int data;
    cin>>data;
    while(data != -1)
    {
        root = insertIntoBST(root, data);
        cin>>data;
    }
}

/*
[Recursive]
T.C -> O(height) [Worst Case - O(n)] 
S.C ->O(height)
*/
bool searchInBST(Node* root, int x) {
    if(root == NULL)
        return false;
    
    if(root->data == x)
    {
        return true;
    }

    if(x < root->data)
        return searchInBST(root->left, x);
    
    else
        return searchInBST(root->right, x);
}

/*
[Iterative]
T.C -> O(height) [Worst Case - O(n)] 
S.C -> O(1)
*/
bool searchInBST_2(Node* root, int x) {
    Node* temp = root;
    while(temp != NULL)
    {
        if(temp->data == x)
        {
            return true;
        }
        
        if(x < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return false;
}

Node* minVal(Node* root)
{
    Node* temp = root;
    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node* maxVal(Node* root)
{
    Node* temp = root;
    while(temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

//To Find Inorder Predecessor and Successor
void findPreSuc(Node* &root, int &pre, int &suc, int key)
{
    if(root == NULL)
        return;
        
    if(root->data == key)
    {
        if(root->left != NULL)
        {
            Node* temp = root->left;
            while(temp->right != NULL)
                temp = temp->right;
            pre = temp->data;
        }
        
        if(root->right != NULL)
        {
            Node* temp = root->right;
            while(temp->left != NULL)
                temp = temp->left;
            suc = temp->data;
        }
        return;
    }
    
    if(key < root->data)
    {
        suc = root->data;
        findPreSuc(root->left, pre, suc, key);
    }
    
    else
    {
        pre = root->data;
        findPreSuc(root->right, pre, suc, key);
    }
}

/*
T.C -> O(height) [Worst Case - O(n)] 
S.C -> O(1)
*/
Node* deleteFromBST(Node* root, int key)
{
    if(root == NULL)
        return root;
    
    if(root->data == key)
    {
        //0 child
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        
        //1 child
        
        //left child
        if(root->left != NULL && root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        //right child
        if(root->left == NULL && root->right != NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        
        //2 child
        if(root->left != NULL && root->right != NULL)
        {
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }
    
    if(key < root->data)
    {
        root->left = deleteFromBST(root->left, key);
        return root;
    }
    else
    {
        root->right = deleteFromBST(root->right, key);
        return root;
    }
}

int main()
{
    Node* root = NULL;
    
    cout<<"Enter data to create BST: "<<endl;
    takeInput(root);
    
    cout<<endl<<"Printing the BST: "<<endl;
    levelOrderTraversal(root);
    
    cout<<endl<<"Printing Preorder: "<<endl;
    preorder(root);
     
    cout<<endl<<"Printing Inorder: "<<endl;
    inorder(root);
    
    cout<<endl<<"Printing Postorder: "<<endl;
    postorder(root);

    cout<<endl<<endl<<"Enter the element to search: ";
    int x;
    cin>>x;
    cout<<endl<<"Is "<<x<<" present? : "<<searchInBST(root, 8);

    cout<<endl<<endl<<"Minimum Value in BST: "<<minVal(root)->data;
    cout<<endl<<"Maximum Value in BST: "<<maxVal(root)->data;

    cout<<endl<<endl<<"Enter the element for it's inorder predecessor and successor: ";
    int key, suc, pre;
    cin>>key;
    suc = pre = -1;
    findPreSuc(root, pre, suc, key);
    cout<<endl<<"Inorder Predecessor of "<<key<<" : "<<pre;
    cout<<endl<<"Inorder Successor of "<<key<<" : "<<suc;

    cout<<endl<<"Enter a Node to delete: ";
    int del;
    cin>>del;
    root = deleteFromBST(root, del);
    cout<<endl<<"Printing the BST after deletion: "<<endl;
    levelOrderTraversal(root);
    return 0;
}
