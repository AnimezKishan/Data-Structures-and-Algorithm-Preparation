#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

*************************************************************/

/*

-> Flatten root1 and root2 into sorted LL
-> Merge two sorted LL
-> Turn sorted LL into BST

T.C -> O(m+n) [m = size of root1, n = size of root2]
S.C -> O(1)

*/

void convertIntoSortedDLL(TreeNode<int>* root, TreeNode<int>* &head)
{
    if(root == NULL)
        return;
    
    convertIntoSortedDLL(root->right, head);

    root->right = head;

    if(head != NULL)
        head->left = root;

    head = root;

    convertIntoSortedDLL(root->left, head);
}

TreeNode<int>* mergedLL(TreeNode<int> *head1, TreeNode<int> *head2)
{
    TreeNode<int> *head = NULL;
    TreeNode<int> *tail = NULL;

    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data < head2->data)
        {
            if(head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if(head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while(head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while(head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;

} 

int countNodes(TreeNode<int> *head)
{
    int cnt = 0;
    TreeNode<int> *temp = head;
    while(temp != NULL)
    {
        temp = temp->right;
        cnt++;
    }
    return cnt;
}

TreeNode<int>* sortedLLToBST(TreeNode<int>* &head, int n)
{
    if(n <= 0 || head == NULL)
        return NULL;

    TreeNode<int> *left = sortedLLToBST(head, n/2);

    TreeNode<int> *root = head;
    root->left = left;

    head = head->right;
    
    root->right = sortedLLToBST(head, n-n/2-1);
    return root;

}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    
    // Flatten root1 and root2 into sorted LL
    TreeNode<int> *head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left = NULL;

    TreeNode<int> *head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2->left = NULL;

    // Merge two sorted LL
    TreeNode<int> *head = mergedLL(head1, head2);

    return sortedLLToBST(head, countNodes(head));

}