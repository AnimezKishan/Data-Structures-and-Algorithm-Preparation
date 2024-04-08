class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int notEaten = 0;
        int sandwichIdx = 0;

        while(students.size() && notEaten < students.size()){
            if(students[0] == sandwiches[sandwichIdx]){
                notEaten = 0;
                
                students.erase(students.begin());
                sandwichIdx++;
            }
            else{
                notEaten++;
                int temp = students[0];
                students.erase(students.begin());
                students.push_back(temp);
            }
        }

        return students.size();

    }
};