class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n = seats.size();
        sort(begin(seats), end(seats));
        sort(begin(students), end(students));

        int ans = 0;
        for(int i=0; i<n; i++)
            ans += abs(students[i] - seats[i]);
        

        return ans;
    }
};