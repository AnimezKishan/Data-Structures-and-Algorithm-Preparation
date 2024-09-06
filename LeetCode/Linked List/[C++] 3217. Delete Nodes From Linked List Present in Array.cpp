/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, bool> deleteNode;
        for(int &num : nums)
            deleteNode[num] = true;
        ListNode *temp = new ListNode(-1, head);

        ListNode *ans = temp;
        while(temp) {
            while(temp->next && deleteNode.find(temp->next->val) != deleteNode.end()){
                ListNode* del = temp->next;
                temp->next = temp->next->next;
                delete(del);
            }

            temp = temp->next;
        }

        return ans->next;
    }
};