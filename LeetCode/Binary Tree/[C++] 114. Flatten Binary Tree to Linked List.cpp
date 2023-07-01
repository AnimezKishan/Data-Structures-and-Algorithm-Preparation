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

/*
 T.C -> O(n)
 S.C -> O(1) [No recursion or stack used]
*/
 
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;

        TreeNode *curr, *pre;
        curr = root;

        while(curr != NULL)
        {
            if(curr->left != NULL)
            {
                //get predecssor for current node
                pre = curr->left;
                while(pre->right != NULL)
                    pre = pre->right;
                
                //make the predecessor's right point to current's right
                pre->right = curr->right;
                //make current node right's point to left
                curr->right = curr->left;
            }
            curr = curr->right;
        }

        //left part
        curr = root;
        while(curr != NULL)
        {
            //make all left part point to null
            curr->left = NULL;
            curr = curr->right;
        }
    }
};