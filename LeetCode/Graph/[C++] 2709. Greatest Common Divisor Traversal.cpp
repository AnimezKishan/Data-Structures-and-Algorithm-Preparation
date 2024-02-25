// Disjoint Set Union (By Rank)
class DSU {
    vector<int> parent;
    vector<int> rank;
    int numberOfComponents;
    public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n);
        numberOfComponents = n;

        for(int i=0;i<n;i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x){
        if(x == parent[x])
            return x;
        
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) 
            return;
        
        if (rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }
        else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } 
        else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }

        numberOfComponents -= 1;
    } 

    int checkNoOfComponents() {
        return numberOfComponents;
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> factorToIndex;

        DSU dsu(n);

        for(int i=0;i<n;i++){
            for(int factor=2;factor*factor<=nums[i];factor++){

                if(nums[i] % factor != 0)
                    continue;
                
                if(factorToIndex.find(factor) != factorToIndex.end())
                    dsu.Union(factorToIndex[factor], i);
                else
                    factorToIndex[factor] = i;
                
                while(nums[i] % factor == 0)
                    nums[i] /= factor;
            }

            if(nums[i] > 1){
                if(factorToIndex.find(nums[i]) != factorToIndex.end())
                    dsu.Union(factorToIndex[nums[i]], i);
                else
                    factorToIndex[nums[i]] = i;
            }
        }

        return dsu.checkNoOfComponents() == 1; 
    }
}; 