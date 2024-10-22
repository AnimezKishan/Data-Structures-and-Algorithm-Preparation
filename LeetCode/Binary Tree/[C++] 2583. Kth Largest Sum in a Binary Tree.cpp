// Heap

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
    typedef long long ll;
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<ll, vector<ll>, greater<ll>> pq; // min-heap
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            ll levelSum = 0;
            while(n--){
                TreeNode* temp = q.front();
                q.pop();

                levelSum += temp->val;

                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }

            pq.push(levelSum);
            if(pq.size() > k)
                pq.pop();
        }

        return pq.size() < k ? -1 : pq.top();
    }
};