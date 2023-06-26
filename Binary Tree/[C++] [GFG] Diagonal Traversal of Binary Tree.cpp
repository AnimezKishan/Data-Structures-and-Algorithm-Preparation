/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*
Time Complexity: O(N), because we are visiting nodes once.
Auxiliary Space: O(N), because we are using a queue.
*/

vector<int> diagonal(Node *root)
{
   // your code here
   vector<int> ans;
   if(root == NULL)
    return ans;
   queue<Node*> q;
   
   q.push(root);
   
   while(!q.empty())
   {
       //size represents the current node which to be traversed and left over nodes which falls in same diagonal 
       int size = q.size();
       vector<int> tempAns;
       
       while(size--)
       {
           Node* temp = q.front();
           q.pop();
           
           //traverse each element
           while(temp != NULL)
           {
               tempAns.push_back(temp->data);
               
               //enque left over nodes in the queue
               if(temp->left)
                q.push(temp->left);
               
               //traverse all right nodes of diagonal
               temp = temp->right;
           }
       }
       for(i:tempAns)
        ans.push_back(i);
   }
   return ans;
}