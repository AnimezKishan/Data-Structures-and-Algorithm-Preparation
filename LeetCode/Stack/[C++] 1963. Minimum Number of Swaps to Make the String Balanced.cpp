/*
After removing already present balanced brackets, the following pattern would be formed
][ -> takes 1 pair swap
]][[ -> takes 1 pair swap
]]][[[ -> takes 2 pair swap
]]]][[[[ -> takes 2 pair swap

So, no. of swaps = (no. of opening brackets + 1) /2
As, even no. of open brackets takes same no. of swaps as just previous odd no. of open brackets. 
e.x. - no. of swaps for 4 open brackets = no. of swaps for 3 open brackets
*/

class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;

        for(char &ch : s){
            if(ch == '[')
                st.push(ch);
            else if(!st.empty())
                st.pop();
        }

        return (st.size()+1)/2;
    }
};