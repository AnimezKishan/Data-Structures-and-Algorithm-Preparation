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
 -> Store the level order traversal.
 -> Extract the maximum value from each level.
*/

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root)
            return {};
        
        vector<vector<int>> tree;
        vector<int> curr_lvl;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            auto *temp = q.front();
            q.pop();

            if(!temp){
                tree.push_back(curr_lvl);
                curr_lvl.resize(0);

                if(!q.empty())
                    q.push(NULL);
            }
            else{
                curr_lvl.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }

        // for(int i=0;i<tree.size();i++){
        //     for(int j=0;j<tree[i].size();j++)
        //         cout<<tree[i][j]<<" ";
        //     cout<<endl;
        // }

        vector<int> ans;
        for(int i=0;i<tree.size();i++)
            ans.push_back(*max_element(begin(tree[i]), end(tree[i])));
        
        return ans;
    }
};

// Optimized code - keep track of maximum value for each level
/*
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root)
            return {};
            
        queue<TreeNode*> q;
        q.push(root);

        vector<int> ans;
        while(!q.empty()) {
            int n = q.size();
            int maxi = INT_MIN;
            while(n--) {
                TreeNode* curr = q.front();
                q.pop();

                maxi = max(maxi, curr->val);

                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            ans.push_back(maxi);
        }

        return ans;
    }
};
 */