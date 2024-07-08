// Simulation

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> persons;

        for(int i=1; i<=n; i++)
            persons.push_back(i);

        int i = 0;
        while(persons.size() > 1){
            int idx = (i+k-1)%persons.size();
            persons.erase(persons.begin()+idx);
            i = idx;
        }

        return persons[0];
    }
};