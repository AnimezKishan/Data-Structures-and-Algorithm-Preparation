/*
Example - 
4,1,6
Therefore, water trapped in 1st index = min(4,6)-1
To get the water trapped in current index:
    -> find min between left most greatest value and right most greatest value
    -> subtract with current height of building.
*/
class Solution {
public:
    vector<int> temp;
    int n;
    vector<int> getLeftMax(vector<int>& height){
        temp.resize(n, 0);
        temp[0] = height[0];

        for(int i=1;i<n;i++)
            temp[i] = max(temp[i-1], height[i]);

        return temp;
    }

    vector<int> getRightMax(vector<int>& height){
        temp.resize(n, 0);
        temp[n-1] = height[n-1];

        for(int i=n-2;i>=0;i--)
            temp[i] = max(temp[i+1], height[i]);

        return temp;
    }
    int trap(vector<int>& height) {
        n = height.size();

        vector<int> leftMaxArray = getLeftMax(height);
        vector<int> rightMaxArray = getRightMax(height);

        int ans = 0;
        for(int i=0;i<n;i++){
            ans += min(leftMaxArray[i], rightMaxArray[i]) - height[i];
        }

        return ans;
    }
};