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
 -> Find the Least Common Ancestor of src and dest
 -> Now find distance between LCA node and src and between LCA node and dest.
 -> As you'll always move up from start to LCA, then LCA to dest. So, make the string acccordingly.
 */

class Solution {
public:
    TreeNode* leastCommonAncestor(TreeNode* root, int src, int dest){
        if(!root)
            return NULL;
        
        if(root->val == src || root->val == dest)
            return root;

        TreeNode* left = leastCommonAncestor(root->left, src, dest);
        TreeNode* right = leastCommonAncestor(root->right, src, dest);

        if(left && right)
            return root;
        
        return left ? left : right;
    }

    bool findPath(TreeNode *root, int dest, string &path){
        if(!root)
            return false;

        if(root->val == dest){
            return true;
        }

        path += 'L';
        if(findPath(root->left, dest, path) == true)
            return true;
        path.pop_back();

        path += 'R';
        if(findPath(root->right, dest, path) == true)
            return true;
        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA = leastCommonAncestor(root, startValue, destValue);
        string lcaToSrc = "", lcaToDest = "";
        findPath(LCA, startValue, lcaToSrc);
        findPath(LCA, destValue, lcaToDest);

        string ans = "";
        for(char &path : lcaToSrc)
            ans += 'U';
        
        ans += lcaToDest;
        return ans;
    }
};