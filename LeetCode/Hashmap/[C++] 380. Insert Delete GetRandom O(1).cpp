class RandomizedSet {
public:
    int i = 0;
    vector<int> arr;
    unordered_map<int, int> noToIndex;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(noToIndex.find(val) == noToIndex.end()){
            arr.push_back(val);
            noToIndex[val] = i;
            i++;
            return true;
        }
        else
            return false;
    }
    
    bool remove(int val) {
        if(noToIndex.find(val) == noToIndex.end()){
            return false;
        }
        else{
            int last_elem = arr.back();
            swap(arr[noToIndex[val]], arr[i-1]);
            noToIndex[last_elem] = noToIndex[val];
            arr.pop_back();
            i--;
            noToIndex.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        int N = arr.size();
        int r = rand() % N;
        return arr[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */