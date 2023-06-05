/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

/*
1. create a clone list (using the next pointer of original LL)
2. To copy random pointer,
   create a map for clone list and original list.
   point the cloneLL->random = map[originalLL->random]

T.C - O(N)
S.C - O(N)
*/
class Solution {
private:
    void insertAtTail(Node* &head, Node* &tail, int d){
        Node* nodeToInsert = new Node(d);
        if(head == NULL)
        {
            head = nodeToInsert;
            tail = nodeToInsert;
            return;
        }
        
        tail->next = nodeToInsert;
        tail = tail->next;
    }
public:
    Node* copyRandomList(Node* head) {

        //1. Create a clone list with next pointer
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        while(temp != NULL)
        {
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }

        //2. Create a map
        unordered_map<Node* , Node*> oldToNew;

        temp = head;
        Node* temp2 = cloneHead;
        while(temp != NULL && temp2 != NULL){
            oldToNew[temp] = temp2;
            temp = temp->next;
            temp2 = temp2->next;
        }

        Node *cloneNode = cloneHead;
        Node *originalNode = head;

        while(cloneNode != NULL){
            cloneNode->random = oldToNew[originalNode->random];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        return cloneHead;
    }
};