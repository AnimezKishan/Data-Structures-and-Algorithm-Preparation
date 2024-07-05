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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> pointPositions;

        ListNode* temp = head->next;
        int prevNode = head->val, pos = 1;
        while(temp->next){
            if((temp->val > prevNode && temp->val > temp->next->val) || (temp->val < prevNode && temp->val < temp->next->val)){
                pointPositions.push_back(pos);
            }

            prevNode = temp->val;
            pos++;
            temp = temp->next;
        }

        int n = pointPositions.size();
        if(n < 2)
            return {-1, -1};
        
        // First and last point would always cause the max distance. 
        int minDistance = INT_MAX, maxDistance = pointPositions[n-1] - pointPositions[0];
        //For minimum distance, find two adjacent points with min distance.
        for(int i=0; i<n-1; i++)
            minDistance = min(minDistance, pointPositions[i+1] - pointPositions[i]);
        

        return {minDistance, maxDistance};
    }
};