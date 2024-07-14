class Solution {
public:
    typedef unordered_map<string, int> MAP;
    string countOfAtoms(string formula) {
        int n = formula.length();

        stack<MAP> st;
        st.push(MAP());
        int i = 0;

        while(i < n){
            if(formula[i] == '('){
                st.push(MAP());
                i++;
            }
            else if(formula[i] == ')'){
                MAP currMap = st.top();
                st.pop();
                i++;
                string multiplier;
                while(i < n && isdigit(formula[i])){
                    multiplier += formula[i];
                    i++;
                } 

                if(!multiplier.empty()){
                    int mult = stoi(multiplier);
                    for(auto &[atom, count] : currMap)
                        currMap[atom] = count * mult;
                }

                for(auto &[atom, count] : currMap)
                    st.top()[atom] += count;
            }
            else{
                string currAtom = "";
                currAtom += formula[i];
                i++;

                while(i < n && islower(formula[i])){
                    currAtom += formula[i];
                    i++;
                }

                string currCount = "";

                while(i < n && isdigit(formula[i])){
                    currCount += formula[i]; 
                    i++;
                }

                int count = currCount.empty() ? 1 : stoi(currCount);
                st.top()[currAtom] += count; 
            }
        }

        map<string, int> sortedAtoms(st.top().begin(), st.top().end());

        string ans;
        for(auto &[atom, count] : sortedAtoms){
            ans += atom;
            if(count > 1){
                ans += to_string(count);
            }
        }

        return ans;
    }
};