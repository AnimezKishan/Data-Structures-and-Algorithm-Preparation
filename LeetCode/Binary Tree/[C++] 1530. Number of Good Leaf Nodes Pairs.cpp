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
    unordered_set<TreeNode*> leafNodes;
    void makeAdj(TreeNode *root, unordered_map<TreeNode*, vector<TreeNode*>> &adj){
        if(!root)
            return;

        if(!root->left && !root->right)
            leafNodes.insert(root);
        
        if(root->left){
            adj[root].push_back(root->left);
            adj[root->left].push_back(root);
            makeAdj(root->left, adj);
        }

        if(root->right){
            adj[root].push_back(root->right);
            adj[root->right].push_back(root);
            makeAdj(root->right, adj);
        }
    }

    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> adj;
        makeAdj(root, adj);

        // for(auto &i : adj){
        //     cout<<i.first<<" -> ";
        //     for(int &j : i.second)
        //         cout<<j<<", ";
        //     cout<<endl;
        // }

        int ans = 0;
        // BFS for every leaf node
        for(auto &leaf : leafNodes){
            queue<TreeNode*> q;
            unordered_set<TreeNode*> visited;
            q.push(leaf);
            visited.insert(leaf);

            for(int level = 0; level <= distance; level++){
                int size = q.size();
                while(size--){
                    TreeNode* u = q.front();
                    q.pop();

                    if(u != leaf && leafNodes.count(u))
                        ans++;

                    for(auto &v : adj[u]){
                        if(!visited.count(v)){
                            visited.insert(v);
                            q.push(v);
                        }
                    }
                }
            }
        }
        
        // remove duplicate entries
        return ans/2;
    }
};