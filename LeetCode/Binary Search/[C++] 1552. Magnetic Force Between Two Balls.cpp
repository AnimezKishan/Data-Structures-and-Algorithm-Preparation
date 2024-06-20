class Solution {
public:
    bool isPossible(int mid, vector<int> &position, int &m){
        int noOfBalls = 1, currBallPosition = position[0];
        for(auto &i : position){
            if(i-currBallPosition >= mid){
                noOfBalls++;
                currBallPosition = i;
            }
        }

        return noOfBalls >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(begin(position), end(position));

        int s = 0, e = *max_element(begin(position), end(position)), ans = -1;
        
        while(s <= e){
            int mid = s + (e-s)/2;

            if(isPossible(mid, position, m)){
                ans = mid;
                s = mid + 1;
            }
            else
                e = mid - 1;
        }

        return ans;
    }
};