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
 First Value of Pair: Diameter
 Seconf Value of Pair: Height

 T.C -> O(n)
 S.C -> O(max heightof tree)
 */
class Solution {
private:
    pair<int, int> diameter(TreeNode* root){
        if(root == NULL)
        {
            pair<int, int> p = make_pair(0,0);
            return p;
        }

        pair<int, int> left = diameter(root->left);
        pair<int, int> right = diameter(root->right);

        int opt1 = left.first;
        int opt2 = right.first;
        int opt3 = left.second + right.second + 1;

        pair<int, int> ans;
        ans.first = max(opt1, max(opt2, opt3));
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root).first-1;
    }
};