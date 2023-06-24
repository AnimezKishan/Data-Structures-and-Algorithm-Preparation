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
S.C -> O(n)
*/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while(!q.empty())
        {
            int size = q.size();
            vector<int> tempAns(size);

            for(int i=0;i<size;i++)
            {
                TreeNode* temp = q.front();
                q.pop();

                //decides whether to traverse left_to_right or right_or_left
                int index = leftToRight? i : size-i-1;
                tempAns[index] = temp->val;

                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }

            //to change direction
            leftToRight = !leftToRight;
            ans.push_back(tempAns);
        }
        return ans;
    }
};