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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> childSet;

        for(auto &description : descriptions){
            int currParent = description[0];
            int currChild = description[1];
            int isLeft = description[2];

            if(mp.find(currParent) == mp.end()){
                mp[currParent] = new TreeNode(currParent);
            }

            if(mp.find(currChild) == mp.end())
                mp[currChild] = new TreeNode(currChild);

            if(isLeft)
                mp[currParent]->left = mp[currChild];
            else
                mp[currParent]->right = mp[currChild];
            
            childSet.insert(currChild);
        }

        // Find root node
        for(auto &description : descriptions){
            int parent = description[0];

            //if any parent is into child set
            if(childSet.find(parent) == childSet.end())
                return mp[parent];
        }
        
        return NULL;
    }
};