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
    TreeNode* replaceValueInTree(TreeNode* root) {
        // Level-wise sum
        queue<TreeNode*> q;
        vector<int> levelWiseSum;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            int currLevelSum = 0;
            while(n--){
                TreeNode* temp = q.front();
                q.pop();
                currLevelSum += temp->val;

                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            levelWiseSum.push_back(currLevelSum);
        }

        // Value for a node = levelSum - siblingSum
        // We can get Sibling Sum using the parent node
        q.push(root);
        int i = 1;
        root->val = 0; // root node has no cousins

        while(!q.empty()){
            int n = q.size();
            while(n--) {
                TreeNode *temp = q.front();
                q.pop();

                int siblingSum = temp->left ? temp->left->val : 0; 
                siblingSum += temp->right ? temp->right->val : 0; 

                if(temp->left){
                    temp->left->val = levelWiseSum[i] - siblingSum;
                    q.push(temp->left);
                }
                if(temp->right){
                    temp->right->val = levelWiseSum[i] - siblingSum;
                    q.push(temp->right);
                }
            }
            i++;
        }

        return root;
    }
};