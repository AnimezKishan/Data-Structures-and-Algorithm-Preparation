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
S.C -> O(max height of tree)
*/

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<TreeNode*> q;
        stack<TreeNode*> s;
        q.push(root);
        q.push(NULL);

        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            s.push(temp);

            if(temp == NULL)
            {
                if(!q.empty())
                    q.push(NULL);
            }
            else
            {
                //NOTE - In this, we are pushing right child first as we are using stack later on.
                if(temp->right)
                    q.push(temp->right);
                if(temp->left)
                    q.push(temp->left);
            }
            
        }

        //to remove the last NULL so that stack can function properly.    
        s.pop();

        vector<int> insert;
        while(!s.empty())
        {
            TreeNode* t = s.top();
            if(s.top() == NULL)
            {
                ans.push_back(insert);
                insert.resize(0);
                s.pop();
            }
            else
            {
                insert.push_back(t->val);
                s.pop();
            }
        }
        ans.push_back(insert);
        return ans;
    }
};