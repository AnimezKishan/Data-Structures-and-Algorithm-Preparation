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
 S.C -> O(max height of tree)
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

/*
Approach II - Calculate diameter for every node treating it as root node.
class Solution {
public:
    int ans = INT_MIN;
    void solve2(TreeNode* root, int depth, int &ans){
        if(!root){
            if(ans < depth)
                ans = depth;
            return;
        }
        
        depth++;

        solve2(root->left, depth, ans);
        solve2(root->right, depth, ans);
    }
    void solve1(TreeNode* root){
        if(!root)
            return;
        
        int leftP = 0, rightP = 0;
        solve2(root->left, 0, leftP);
        solve2(root->right, 0, rightP);

        ans = max(ans, leftP+rightP);

        if(root->left)
            solve1(root->left);

        if(root->right)
            solve1(root->right);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve1(root);
        return ans; 
    }
};
*/