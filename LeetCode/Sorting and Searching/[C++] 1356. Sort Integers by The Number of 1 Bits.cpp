// O(n*log(n)) * O(log2(num))
class Solution {
public:

    //O(log2(num))
    int findOneCount(int x){
        int ans = 0;
        while(x){
            ans += (x&1);
            x >>= 1;
        }
        return ans;
    }

    //O(n*log(n))
    vector<int> sortByBits(vector<int>& arr) {

        // [] is capture clause, if [&] is used then lambda function can use functions and variables outside of itself.
        //Here, it helps to use findOneCount().
        auto compare = [&](int &a, int &b){

            // there's also a built-in function "__builtin_popcount()" which returns no. of 1 bit in a number in O(1).
            int countA = findOneCount(a); 
            int countB = findOneCount(b);

            if(countA == countB)
                return a < b;
            
            return countA < countB;
        };

        sort(begin(arr), end(arr), compare);
        return arr;
    }
};


/*
Initial Intuition [ Bit Manipulation + Min Heap ].

class Solution {
public:
    typedef pair<int, int> P;
    vector<int> sortByBits(vector<int>& arr) {
        priority_queue<P, vector<P>, greater<P>> min_heap;

        for(int i=0;i<arr.size();i++){
            int count = 0;
            int temp = arr[i];
            while(arr[i]){
                if(arr[i]&1)
                    count++;
                arr[i] = arr[i]>>1;
            }

            min_heap.push({count, temp});
        }

        vector<int> ans;
        while(!min_heap.empty()){
            auto t = min_heap.top();
            min_heap.pop();

            ans.push_back(t.second);
        }

        return ans;
    }
};
*/