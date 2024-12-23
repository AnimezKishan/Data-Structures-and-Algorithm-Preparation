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
    int findMinOperations(vector<int> &arr) {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> mp;
        for(int i=0; i<sorted.size(); i++) {
            mp[arr[i]] = i;
        }

        int swaps = 0;
        for(int i=0; i<arr.size(); i++) {
            if(arr[i] != sorted[i]){
                int correctIdx = mp[sorted[i]];
                mp[arr[i]] = correctIdx;
                mp[arr[correctIdx]] = i;

                swap(arr[i], arr[correctIdx]);
                swaps++;
            }
        }

        return swaps;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int ans = 0;
        while(!q.empty()) {
            int n = q.size();
            vector<int> lvlElems;
            while(n--) {
                TreeNode* curr = q.front();
                q.pop();

                lvlElems.push_back(curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }

            ans += findMinOperations(lvlElems);
        }

        return ans;
    }
};