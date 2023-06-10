/*
** Solve "Largest Rectangle in Histogram" before solving this. **
T.C -> O((n*m) + (n*m))
one (n*m) for algorithm and another to convert the vector into 'int'

S.C -> O(matrix[0].size())

Algo ->
1. Compute area for first row
2. Iterate for remaining rows and add them with the previous row
3. Compute area among rest.
*/
class Solution {
private:
    vector<int> nextSmallerElement(vector<int> &heights, int n){
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        for(int i = n-1;i>=0;i--)
        {
            int curr = heights[i];
            while(st.top() != -1 && heights[st.top()] >= curr)
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int> &heights, int n){
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        for(int i = 0;i<n;i++)
        {
            int curr = heights[i];
            while(st.top() != -1 && heights[st.top()] >= curr)
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int> &heights, int n) {

        vector<int> next(n);
        next = nextSmallerElement(heights, n);

        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);

        int area = INT_MIN;
        for(int i=0;i<n;i++)
        {
            int l = heights[i];
            
            /*
            edge case - if all elements are of same heigth then next amd prev both will consist -1, this gives 'b'
            as -1
            */

            if(next[i] == -1)
                next[i] = n;
            int b = next[i] - prev[i] - 1;
            int newArea = l*b;
            area = max(area, newArea);
        }
        return area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> heights(matrix.size());
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                int push = matrix[i][j] - '0';
                heights[i].push_back(push);
            }
        }
        int n = heights.size();
        int area = largestRectangleArea(heights[0], heights[0].size());
        for(int i=1;i<heights.size();i++)
        {
            for(int j=0;j<heights[i].size();j++)
            {
                if(heights[i][j] != 0)
                    heights[i][j] += heights[i-1][j];
                else
                    heights[i][j] = 0;
            }
            area = max(area, largestRectangleArea(heights[i], heights[i].size()));
        }
        return area;
    }
};