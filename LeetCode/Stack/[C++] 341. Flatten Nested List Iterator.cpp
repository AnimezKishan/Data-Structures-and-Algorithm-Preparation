/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    stack<NestedInteger> st;
    NestedIterator(vector<NestedInteger> &nestedList) {
        int n = nestedList.size();
        for(int i=n-1;i>=0;i--){
            st.push(nestedList[i]);
        }
    }
    
    int next() {
        auto obj = st.top().getInteger();
        st.pop();
        return obj;
    }
    
    bool hasNext() {
        while(!st.empty()){
            auto obj = st.top();

            if(obj.isInteger()){
                return true;
            }

            st.pop();
            vector<NestedInteger> tempObj = obj.getList();
            for(int i=tempObj.size()-1;i>=0;i--){
                st.push(tempObj[i]);
            }

        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */