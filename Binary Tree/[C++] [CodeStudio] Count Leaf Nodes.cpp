/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
    };
    
***********************************************************/
void countLeaf(BinaryTreeNode<int> *root, int &ans)
{
    //base case
    if (root == NULL) {
      return;
    }

    countLeaf(root->left, ans);

    if(root->left == NULL && root->right == NULL)
        ans++;
    
    countLeaf(root->right, ans);


}

int noOfLeafNodes(BinaryTreeNode<int> *root){
    // Write your code here.
    int ans = 0;
    countLeaf(root, ans);
    return ans;
}