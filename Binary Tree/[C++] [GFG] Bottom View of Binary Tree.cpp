/*
T.C -> O(n*log(n)) [log(n) for accessing map] {can be done in O(n) using unordered_map}
S.C -> O(n)
*/

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        
        map<int, int> bottomNode;
        queue<pair<Node* , int>> q;
        
        q.push({root, 0});
        
        while(!q.empty())
        {
            pair<Node*, int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            bottomNode[hd] = frontNode->data;
            
            if(frontNode->left)
                q.push({frontNode->left, hd-1});
            if(frontNode->right)
                q.push({frontNode->right, hd+1});
        }
        
        for(i:bottomNode)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};