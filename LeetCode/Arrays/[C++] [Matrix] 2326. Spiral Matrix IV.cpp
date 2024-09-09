class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));

        int dir    = 0; // 0, 1, 2, 3
        int top   = 0;
        int down  = m-1;
        int left  = 0;
        int right = n-1;

        while(top <= down && left <= right) {
            if(dir == 0) { //left to right
                for(int i = left; head && i <= right; i++) {
                    matrix[top][i] = head->val;
                    head = head->next;
                }
                top++;
            }

            if(dir == 1) { //top to down
                for(int i = top; head && i <= down; i++) {
                    matrix[i][right] = head->val;
                    head = head->next;
                }
                right--;
            }

            if(dir == 2) { //right to left
                for(int i = right; head && i >= left; i--) {
                    matrix[down][i] = head->val;
                    head = head->next;
                }
                down--;
            }

            if(dir == 3) { //down to top
                for(int i = down; head && i >= top; i--) {
                    matrix[i][left] = head->val;
                    head = head->next;
                }
                left++;
            }

            dir = (dir+1)%4; // 0, 1, 2, 3
        }

        return matrix;
    }
};