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
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<int> lvlVals;
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 0, n;

        while(!q.empty()) {
            n = q.size();
            while(n--) {
                TreeNode* curr = q.front();
                q.pop();

                // save all values for odd level using it's parent
                if(lvl % 2 == 0 && curr->left)
                    lvlVals.push_back(curr->left->val);
                if(lvl % 2 == 0 && curr->right)
                    lvlVals.push_back(curr->right->val);

                // store values in reverse order for odd level
                if(lvl&1) {
                    curr->val = lvlVals[lvlVals.size()-1];
                    lvlVals.pop_back();
                }
                
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            lvl++;
        }

        return root;
    }
};