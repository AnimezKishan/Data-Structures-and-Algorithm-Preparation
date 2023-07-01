/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

/*
-> Create mapping for each node with their parents.
-> Find Target node.
-> Craete a map to check if node is visited or not.
-> Create a queue to start traversing from target 
*/

/*
T.C -> O(nlog(n))
S.C -> O(max height)
*/

class Solution {
  public:
    //this function creates mapping and returns target node
    Node* createParentMapping(Node* root, int target, map<Node*, Node*> &nodeToParent){
        Node* res = NULL;
        queue<Node*> q;
        
        q.push(root);
        nodeToParent[root] = NULL;
        
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();
            
            if(temp->data == target)
                res = temp;
            
            if(temp->left)
            {
                nodeToParent[temp->left] = temp;
                q.push(temp->left);
            }
            
            if(temp->right)
            {
                nodeToParent[temp->right] = temp;
                q.push(temp->right);
            }
        }
        
        return res;
    }
    
    int burnTree(Node* root, map<Node*, Node*> &nodeToParent){
        
        map<Node*, bool> visited;
        queue<Node*> q;
        int ans = 0;
    
        q.push(root);
        visited[root] = true;
        
        while(!q.empty())
        {
            int size = q.size();
            bool flag = 0;
            for(int i=0;i<size;i++)
            {
                Node* temp = q.front();
                q.pop();
                
                if(temp->left && !visited[temp->left])
                {
                    flag = 1;
                    q.push(temp->left);
                    visited[temp->left] = 1;
                }
                
                if(temp->right && !visited[temp->right])
                {
                    flag = 1;
                    q.push(temp->right);
                    visited[temp->right] = 1;
                }
                
                if(nodeToParent[temp] && !visited[nodeToParent[temp]])
                {
                    flag = 1;
                    q.push(nodeToParent[temp]);
                    visited[nodeToParent[temp]] = 1;
                }
            }
            
            if(flag == 1)
                ans++;
        }
        return ans;
    }
    
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node*, Node*> nodeToParent;
        Node* targetNode = createParentMapping(root, target, nodeToParent);
        
        return burnTree(targetNode, nodeToParent);
    }
};