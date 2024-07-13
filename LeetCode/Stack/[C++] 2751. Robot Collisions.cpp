class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> actualIdx(n);

        iota(actualIdx.begin(), actualIdx.end(), 0); //This will fill the array as -> 0, 1, 2, 3, 4, n-1
        auto lambda = [&](int i, int j){
            return positions[i] < positions[j];
        };

        // sort actual indices based on positions so that we can access health and direction accordingly
        sort(actualIdx.begin(), actualIdx.end(), lambda);

        stack<int> st;
        for(int &currentIdx : actualIdx){
            // push all right dir.s into stack
            if(directions[currentIdx] == 'R'){
                st.push(currentIdx);
            }

            // cancel out for every possible previous right directions if left direction found 
            else{
                while(!st.empty() && healths[currentIdx] > 0){
                    int topIdx = st.top();
                    st.pop();

                    if(healths[currentIdx] == healths[topIdx]){
                        healths[currentIdx] = 0;
                        healths[topIdx] = 0;
                    } 
                    else if(healths[currentIdx] > healths[topIdx]){
                        healths[currentIdx]--;
                        healths[topIdx] = 0;
                    }
                    else{
                        healths[currentIdx] = 0;
                        healths[topIdx]--;
                        st.push(topIdx);
                    }
                }
            }
        }

        vector<int> ans;
        for(int health : healths){
            if(health > 0)
                ans.push_back(health);
        }

        return ans;
    }
};