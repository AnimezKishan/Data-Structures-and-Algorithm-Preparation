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
1. create a clone node with next pointer
2. to avoid using mapping, point originalNode->next to cloneNode
3. point cloneNode->next to in between of originalNode to keep track of original LL
4. to store random pointers in clone, set temp->next->random = temp->random->next
5. revert changes done in setp 2

T.C -> O(N)
S.C -> O(1)
*/
class Solution {
private:
    void insertAtTail(Node* &head, Node* &tail, int d){
        Node* nodeToInsert = new Node(d);
        if(head == NULL){
            head = nodeToInsert;
            tail = nodeToInsert;
        }

        tail->next = nodeToInsert;
        tail = nodeToInsert;
    }
public:
    Node* copyRandomList(Node* head) {
        //Step 1
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head;
        while(temp != NULL)
        {
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }

        //Step 2 & Step 3
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while(originalNode != NULL && cloneNode != NULL)
        {
            //Step 2
            Node* next = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = next;

            //Step 3
            next = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = next;
        }

        //Step 4
        temp = head;
        while(temp != NULL)
        {
            if(temp->next != NULL){
                if(temp->random != NULL)
                    temp->next->random = temp->random->next;
                else
                    temp->next->random = temp->random;
            }
            temp = temp->next->next;
        }

        //Step 5
        originalNode = head;
        cloneNode = cloneHead;
        while(originalNode != NULL && cloneNode != NULL){
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;
            if(originalNode != NULL)
                cloneNode->next = originalNode->next;
            cloneNode = cloneNode->next;
        }
        return cloneHead;
    }
};