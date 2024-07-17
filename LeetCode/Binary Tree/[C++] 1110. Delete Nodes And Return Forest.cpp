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
    vector<TreeNode*> forest;
    TreeNode* dfs(TreeNode* root, unordered_set<int> &to_delete){
        if(!root)
            return NULL;

        root->left = dfs(root->left, to_delete);
        root->right = dfs(root->right, to_delete);

        // make the node NULL if it's in delete array and push the childs into forest if have any.
        if(to_delete.find(root->val) != to_delete.end()){
            if(root->left)
                forest.push_back(root->left);
            
            if(root->right)
                forest.push_back(root->right);
            
            return NULL;
        }
        else
            return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st;
        for(int &n : to_delete)
            st.insert(n);

        dfs(root, st);

        // if main root is not the delete array, then include it.
        if(st.find(root->val) == st.end())
            forest.push_back(root);
        
        return forest;
    }
};