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

// Adjacency List + BFS

class Solution {
public:
    unordered_map<int, vector<int>> adj;
    void solve(TreeNode* root){
        if(!root)
            return;
        
        if(root->left)
        {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            solve(root->left);
        }

        if(root->right)
        {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            solve(root->right);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        solve(root);

        if(adj.size() == 0)
            return 0;

        // for(auto &i:adj){
        //     cout<<i.first<<" -> ";
        //     for(auto &j:adj[i.first])
        //         cout<<j<<", ";
        //     cout<<endl;
        // }

        queue<int> st;
        vector<bool> visited(100001, 0);

        st.push(start);
        visited[start] = 1;
        int ans = 0;

        for(;st.size();ans++){
            int n = st.size();
            while(n--){
                int t = st.front();
                cout<<t<<" ";
                st.pop();

                int temp = 0;
                for(auto &nbr:adj[t]){
                    if(!visited[nbr]){
                        visited[nbr] = 1;
                        st.push(nbr);
                    }
                }
            }
        }

        return ans-1;
    }
};