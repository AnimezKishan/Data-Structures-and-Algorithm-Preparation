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
Here, we create a map which stores Horizontal Distance, Level Order and Elements present in a particular level respectively.

And, a queue which stores iterated Node, Horizontal Distance and Level respectively.
*/

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;

        map<int, map<int, vector<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push(make_pair(root, make_pair(0,0)));

        while(!q.empty())
        {
            pair<TreeNode*, pair<int, int>> temp = q.front();
            q.pop();

            TreeNode* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            nodes[hd][lvl].push_back(frontNode->val);

            if(frontNode->left)
                q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1)));
            if(frontNode->right)
                q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
        }

        for(auto i:nodes)
        {
            //i represents horizontal distance
            vector<int> tempAns;
            for(auto j:i.second)
            {
                //j represents level order according to which values are stored.
                sort(j.second.begin(), j.second.end());
                for(auto it: j.second)
                    tempAns.push_back(it);
            }
            ans.push_back(tempAns);
        }
        return ans;
    }
};