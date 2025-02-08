// Ordered Set

class NumberContainers {
    public:
        unordered_map<int, set<int>> noToIndex;
        unordered_map<int, int> indexToNo;
        NumberContainers() {
            
        }
        
        void change(int index, int number) {
            if(indexToNo.find(index) == indexToNo.end()) {
                indexToNo[index] = number;
                noToIndex[number].insert(index);
            } else {
                int currNum = indexToNo[index];
                noToIndex[currNum].erase(index);
                if(noToIndex[currNum].size() == 0)
                    noToIndex.erase(currNum);
    
                indexToNo[index] = number;
                noToIndex[number].insert(index);
            }
        }
        
        int find(int number) {
            if(noToIndex.find(number) == noToIndex.end())
                return -1;
            return *noToIndex[number].begin();
        }
    };
    
    /**
     * Your NumberContainers object will be instantiated and called as such:
     * NumberContainers* obj = new NumberContainers();
     * obj->change(index,number);
     * int param_2 = obj->find(number);
     */