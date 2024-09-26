// Interval Based

class MyCalendar {
public:
    set<pair<int, int>> st;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        // find the event that occurs just after or at the same time of start, end
        auto it = st.lower_bound({start, end});

        // check for overlap with next event
        if(it != st.end() && it->first < end)
            return false;

        // check for overlap with prev event
        if(it != st.begin()) {
            auto p = prev(it);
            if(start < p->second)
                return false;
        }
        
        st.insert({start, end});
        return true;

    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */