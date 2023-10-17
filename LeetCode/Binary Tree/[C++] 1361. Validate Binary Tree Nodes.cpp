/*
** This question is more of a graph question than binary tree.**

Valid Binary Tree
-> Every child - only one parent.
-> Only one root node and it shouldn't have any parent.
-> connected - only one component.

first two points will be taken care by childToParent map.
After mapping and getting the root node apply BFS/DFS on it and count no. of nodes to check connected or not.
*/
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int, int> childToParent;
        unordered_map<int, vector<int>> adjList;

        // 1. child to parent mapping.
        for(int i=0;i<n;i++){

            int leftC = leftChild[i];
            int rightC = rightChild[i];

            if(leftC != -1)
            {
                adjList[i].push_back(leftC);

                //if a child already has a parent, it voilates as a node should have only one parent.
                if(childToParent.find(leftC) != childToParent.end())
                    return false;
                
                childToParent[leftC] = i;
            }

            if(rightC != -1)
            {
                adjList[i].push_back(rightC);

                if(childToParent.find(rightC) != childToParent.end())
                    return false;
                
                childToParent[rightC] = i;
            }
        }

        // 2. Find root node
        int root = -1;
        for(int i=0;i<n;i++)
        {
            if(childToParent.find(i) == childToParent.end()){

                //checks if tree has multiple root nodes.
                if(root != -1)
                    return false;
                
                root = i;
            }
        }

        //if no root found
        if(root == -1)
            return false;

        //3. check if connected or not.
        queue<int> q;
        q.push(root);
        vector<bool> visited(n, false);
        int count = 0;

        //BFS
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            count++;
            visited[temp] = true;

            for(auto &nbr:adjList[temp]){
                if(!visited[nbr]){
                    q.push(nbr);
                }
            }
        }

        //if BFS traverse all nodes that means it's connected, if not that means it's disconnected.
        return count == n;
    }
};