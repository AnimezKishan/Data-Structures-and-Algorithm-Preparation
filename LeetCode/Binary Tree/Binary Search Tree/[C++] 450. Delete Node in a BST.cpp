/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return root;

        if(root->val == key)
        {
            //0 child
            if(root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }

            //1 child [either left or right]

            //left
            if(root->left != NULL && root->right == NULL)
            {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            //right
            if(root->left == NULL && root->right != NULL)
            {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            //2 child
            if(root->left != NULL && root->right != NULL)
            {
                TreeNode* temp = root->right;
                while(temp->left != NULL)
                    temp = temp->left;

                int mini = temp->val;
                root->val = mini;
                root->right = deleteNode(root->right, mini);
                return root;
            }
        }

        if(key < root->val)
        {
            root->left = deleteNode(root->left, key);
            return root;
        }
        else
        {
            root->right = deleteNode(root->right, key);
            return root;
        }
    }
};